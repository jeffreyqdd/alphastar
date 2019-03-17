#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int kCows, cow_order[1025], steps = 0; //2 ^ 10 = 1024

//merge sort implementation

void Merge(int l, int m, int h)
{
    if (cow_order[l] > cow_order[m + 1])
    {
        for (int i = l, j = m + 1; i <= m; i++, j++)
        {

            swap(cow_order[i], cow_order[j]);
            steps += 2 * (j - i);
        }
    }
}

void MergeSort(int lo, int hi)
{
    if (lo < hi)
    {
        int middle = (lo + hi) / 2;

        MergeSort(lo, middle);
        MergeSort(middle + 1, hi);

        Merge(lo, middle, hi);
    }
}

//something interesting about this format, kCows will always be even since it is 2^n
int main()
{
    int n;
    cin >> n;
    kCows = pow(2, n);

    for (int i = 0; i < kCows; i++)
        cin >> cow_order[i];

    MergeSort(0, kCows - 1);
    cout << steps << endl;

    for (int i = 0; i < kCows; i++)
        cout << cow_order[i] << endl;
}