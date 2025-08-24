#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &arr, int n, int start, int end)
{
    if (start >= end)
        return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    func(arr, n, start + 1, end - 1);
}

void reverseArray(vector<int> &arr)
{
    int n = arr.size();
    func(arr, n, 0, n - 1);
}