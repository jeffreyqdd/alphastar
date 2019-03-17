#include <iostream>
using namespace std;

int kNum, A[501];

void print()
{
    for (int i = 0; i < kNum; i++)
        cout << A[i] << " ";
    cout << endl;
}

int find_partition(int lo, int hi, int pivot)
{
    while (true)
    {
        while (A[lo] < A[pivot] && lo < pivot)
            lo++;

        while (A[hi] > A[pivot] && hi > lo)
            hi--;

        if (lo >= hi)
            break;
        else
        {
            swap(A[lo], A[hi]);
            lo++;
            hi--;
        }
    }

    swap(A[lo], A[pivot]);
    print();

    return lo;
}

//input: index of first and last items of the array
void quick_sort(int lo, int hi)
{
    if (hi - lo <= 0)
        return;
    else
    {
        //first is lo, last is hi - 1 (second last), pivot is hi (last)
        int partition = find_partition(lo, hi - 1, hi);

        //recursive search
        quick_sort(lo, partition - 1);
        quick_sort(partition + 1, hi);
    }
    return;
}

int main()
{

    cin >> kNum;

    for (int i = 0; i < kNum; i++)
        cin >> A[i];

    quick_sort(0, kNum - 1);
}