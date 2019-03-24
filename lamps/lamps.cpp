#include <iostream>
#include <vector>
#include <set>
using namespace std;

int kLamps, kToggles, states[10000];
vector<int> lamp_on, lamp_off;

/*
Three buttons:
1: toggle all buttons
2: toggle odd
3: toggle even
4: toggle every third 
*/

//try every subset
vector<int> button_orders;

void button1()
{
    //toggle
    for (int i = 0; i < kLamps; i++)
        states[i] = (states[i] == 1) ? 0 : 1;
}

void button2()
{
    //odd
    for (int i = 1; i < kLamps; i += 2)
        states[i] = (states[i] == 1) ? 0 : 1;
}
void button3()
{
    //even
    for (int i = 0; i < kLamps; i += 2)
        states[i] = (states[i] == 1) ? 0 : 1;
}
void button4()
{
    //third
    for (int i = 0; i < kLamps; i += 3)
        states[i] = (states[i] == 1) ? 0 : 1;
}

set<vector<int>> solutions;
bool isValid(const vector<int> &fp)
{
    for (auto u : lamp_on)
        if (fp[u - 1] == 0)
            return false;

    for (auto u : lamp_off)
        if (fp[u - 1] == 1)
            return false;

    return true;
}

void search(int k)
{
    if (button_orders.size() <= kToggles)
    {
        //reset
        for (int i = 0; i < kLamps; i++)
            states[i] = 1;

        //do buttons
        for (auto u : button_orders)
        {
            if (u == 1)
                button1();
            if (u == 2)
                button2();
            if (u == 3)
                button3();
            if (u == 4)
                button4();
            //cout << u << " ";
        }
        //cout << "-->";
        //for (int i = 0; i < kLamps; i++)
        //cout << states[i] << " ";
        //cout << endl;
        //record
        vector<int> final_pos;
        for (int i = 0; i < kLamps; i++)
            final_pos.push_back(states[i]);

        //insert if valid
        if (isValid(final_pos))
            solutions.insert(final_pos);
    }
    if (k == 5)
        return;

    //search with
    button_orders.push_back(k);
    search(k + 1);

    //search without
    button_orders.pop_back();
    search(k + 1);

    return;
}

int main()
{
    //read
    cin >> kLamps >> kToggles;

    //on lamps
    for (int i = 0; true; i++)
    {
        int l;
        cin >> l;
        if (l == -1)
            break;
        lamp_on.push_back(l);
    }
    //off lamps
    for (int i = 0; true; i++)
    {
        int l;
        cin >> l;
        if (l == -1)
            break;
        lamp_off.push_back(l);
    }

    search(1);

    //write
    for (auto v : solutions)
    {
        for (auto u : v)
        {
            cout << u;
        }
        cout << endl;
    }

    if (solutions.size() == 0)
        cout << "IMPOSSIBLE\n";

    return 0;
}