#include <iostream>
#include <vector>
using namespace std;

int kItems, items[501];

void print(string s, bool nl)
{
    cout << s;
    for (int i = 0; i < kItems; i++)
        cout << items[i] << " ";

    if (nl)
        cout << endl;
}

void Merge(int l, int m, int r)
{
    //l = start, m = dividing line, r = stop

    //cout << l << " " << m << " " << r << endl;

    //unpack into vectors
    vector<int> l1, l2;

    //left chunk
    for (int i = l; i <= m; i++)
        l1.push_back(items[i]);

    //right chunk
    for (int i = m + 1; i <= r; i++)
        l2.push_back(items[i]);

    //merge
    vector<int> c;

    while (!l1.empty() && !l2.empty())
    {
        if (l1[0] < l2[0])
        {
            c.push_back(l1[0]);
            l1.erase(l1.begin());
        }
        else
        {
            c.push_back(l2[0]);
            l2.erase(l2.begin());
        }
    }

    while (!l1.empty())
    {
        c.push_back(l1[0]);
        l1.erase(l1.begin());
    }

    while (!l2.empty())
    {
        c.push_back(l2[0]);
        l2.erase(l2.begin());
    }

    //write to main array;
    for (int i = l, j = 0; i <= r; i++, j++)
        items[i] = c[j];

    print("", 1);
}

void MergeSort(int l, int r)
{
    //recursively slice until size = 2;

    if (l < r)
    {
        int middle = (l + r) / 2;

        MergeSort(l, middle);
        MergeSort(middle + 1, r);

        Merge(l, middle, r);
    }
}

int main()
{
    cin >> kItems;

    for (int i = 0; i < kItems; i++)
        cin >> items[i];

    MergeSort(0, kItems - 1);

    return 0;
}