#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int k, int mid)
{
    int n = arr.size();
    int cnt = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > mid)
        {
            sum = arr[i];
            cnt++;
        }
        else
            sum += arr[i];
    }
    return cnt <= k;
}

int minTime(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

/* Same logic as Split Array Largest Sum problem */