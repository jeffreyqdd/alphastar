#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int kBales, bale_size[21], total = 0, min_hay = 1000;

int maxValue(vector<int> barn1)
{
    int largest = 0;

    if (barn1.empty())
    {
        //cout << "(max value is)" << bale_size[kBales - 1] << "-->";
        return bale_size[kBales - 1];
    }

    for (int i = 0, j = 0; i < kBales; i++)
    {
        if (bale_size[i] == barn1[j])
        {
            j++;
            continue;
        }
        largest = max(largest, bale_size[i]);
    }
    //cout << "(max value is)" << largest << "-->";
    return largest;
}

void search(vector<int> b1, int sum, int index)
{
    /*for (auto u : b1)
        cout << u << " ";
    cout << " --> ";*/

    if (sum >= maxValue(b1) && sum * 3 >= total)
    {
        //update
        //cout << "1 ------------- " << sum << endl;
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