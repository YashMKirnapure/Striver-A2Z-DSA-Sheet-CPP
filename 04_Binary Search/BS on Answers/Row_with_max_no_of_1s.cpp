#include <bits/stdc++.h>
using namespace std;

// LS Search
int rowWithMax1s(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int maxy = 0;
    int rowIdx = -1;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                cnt++;
        }
        if (cnt > maxy)
        {
            maxy = cnt;
            rowIdx = i;
        }
    }
    return maxy == 0 ? -1 : rowIdx;
}

// BS Search
int rowWithMax1s(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int maxy = 0;
    int rowIdx = -1;

    for (int i = 0; i < n; i++)
    {
        int low = 0;
        int high = m - 1;
        int firstOne = m;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[i][mid] == 1)
            {
                firstOne = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        int cnt = m - firstOne;
        if (cnt > maxy)
        {
            maxy = cnt;
            rowIdx = i;
        }
    }
    return maxy == 0 ? -1 : rowIdx;
}

/*
You have a matrix where each row is sorted (0s first, then 1s).

For each row, you use binary search to find the first occurrence of 1.

If found at index firstOne, then the count of 1s = m - firstOne.

If no 1 found, the count is 0.

Track the row with the maximum count of 1s (maxy).

Return the row index if found, else return -1.
*/