#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int idx, int size)
{
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && arr[largest] < arr[left])
        largest = left;
    if (right < size && arr[largest] < arr[right])
        largest = right;

    if (largest != idx)
    {
        swap(arr[largest], arr[idx]);
        heapify(arr, largest, size);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int N)
{
    for (int i = (N / 2) - 1; i >= 0; i--)
        heapify(arr, i, N);
}