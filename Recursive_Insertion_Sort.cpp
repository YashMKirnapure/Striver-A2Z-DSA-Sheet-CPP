#include <iostream>
#include <vector>
using namespace std;

void func(vector<int> &arr, int i, int n)
{
    if (i == n)
        return;

    int j = i;

    while (j > 0 && arr[j - 1] > arr[j])
    {
        swap(arr[j - 1], arr[j]);
        j--;
    }

    func(arr, i + 1, n);
}

vector<int> insertionSort(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    func(arr, i, n);
    return arr;
}
