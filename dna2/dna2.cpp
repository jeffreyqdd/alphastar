#include <iostream>
#include <string>
#include <vector>
using namespace std;

int kStrings, min_length = 100;
string sequences[10];

string Combine(string a, string b)
{
    string output = a;

    int best = 0;
    for (int i = a.size() - 1; i >= int(a.size() - b.size()) && i >= 0; i--)
    {
        //cout << "testing:" << b[0] << " =? " << a[i] << endl;

        if (b[0] == a[i])
        {
            bool flag = false;

            int j = i, k = 0;

            //cout << "entering: ";

            for (; j < a.size(); j++, k++)
            {
                if (a[j] != b[k])
                    flag = true;

                /*cout << "(" << a[j] << "," << b[k] << ")"
                     << " ";*/
            }

            if (flag == false)
                best = k;

            //cout << endl;
        }
    }

    for (int i = best; i < b.size(); i++)
        output = output + b[i];

    return output;
}

int Merge(vector<int> order)
{
    string merged = sequences[order[0]];

    for (int i = 1; i < kStrings; i++)
    {
        int index = order[i];
        merged = Combine(merged, sequences[index]);
    }

    return merged.size();
}

bool chosen[10];
void Permutate(vector<int> order)
{
    if (order.size() == kStrings)
    {
        //process
        min_length = min(min_length, Merge(order));

        return;
    }

    for (int i = 0; i < kStrings; i++)
    {
        if (chosen[i])
            continue;

        order.push_back(i);
        chosen[i] = true;
        Permutate(order);

        chosen[i] = false;
        order.pop_back();
    }

    return;
}

int main()
{

    cin >> kStrings;
    for (int i = 0; i < kStrings; i++)
        cin >> sequences[i];

    Permutate({});

    cout << min_length << endl;

    return 0;
}