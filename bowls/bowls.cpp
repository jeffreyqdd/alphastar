#include <iostream>
#include <vector>
using namespace std;

//always 20 bowls
int best = 1 << 30;

void flip(int index, vector<int> &b)
{
    int lb = max(0, index - 1), ub = min(index + 1, 19);

    for (int i = lb; i <= ub; i++)
        b[i] = (b[i] == 1) ? 0 : 1;

    return;
}

bool isValid(const vector<int> &b)
{
    for (int i = 0; i < 20; i++)
    {
        if (b[i] == 1)
            return false;
    }
    return true;
}

void search(int index, int moves, vector<int> bowls)
{
    if (index == 20)
    {
        if (isValid(bowls))
        {
            best = min(best, moves);
        }
        return;
    }

    //flip and skip

    flip(index, bowls);
    search(index + 1, moves + 1, bowls);

    flip(index, bowls);
    search(index + 1, moves, bowls);

    return;
}

int main()
{
    vector<int> b(20);

    for (int i = 0; i < 20; i++)
        cin >> b[i];

    search(0, 0, b);
    cout << best << endl;

    return 0;
}