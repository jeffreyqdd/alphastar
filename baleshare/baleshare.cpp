#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kBales, bale_size[21], total = 0, min_hay = 1000;

int maxValue(vector<int> barn1)
{
    if (barn1.empty())
        return bale_size[kBales - 1];
    for (int i = kBales - 1, j = barn1.size() - 1; i >= 0; i--)
    {
        if (barn1[j] == bale_size[i])
        {
            j--;
            continue;
        }
        return bale_size[i];
    }
    //should not be here
    return -1;
}

void search(vector<int> b1, int sum, int index)
{
    /*for (auto u : b1)
        cout << u << " ";
    cout << " --> ";*/

    if (sum >= maxValue(b1) && sum * 3 >= total)
    {
        //update
        for (auto u : b1)
            cout << u << " ";
        cout << " --> ";
        cout << "1 ------------- " << sum << endl;
        min_hay = min(min_hay, sum);
        return;
    }
    else if (index == kBales)
    {
        //cout << "0" << endl;
        return;
    }
    //cout << "0" << endl;

    b1.push_back(bale_size[index]);
    search(b1, sum + bale_size[index], index + 1);

    b1.pop_back();
    search(b1, sum, index + 1);

    return;
}

int main()
{
    cin >> kBales;

    for (int i = 0; i < kBales; i++)
    {
        cin >> bale_size[i];
        total += bale_size[i];
    }
    //cout << total << endl;

    sort(bale_size, bale_size + kBales);

    search({}, 0, 0);

    cout << min_hay << endl;

    return 0;
}