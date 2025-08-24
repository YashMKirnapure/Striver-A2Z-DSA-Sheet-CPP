#include <bits/stdc++.h>
using namespace std;

// Method 1
int median(vector<vector<int>> &mat)
{
    vector<int> res;
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res.push_back(mat[i][j]);
        }
    }

    sort(res.begin(), res.end());
    int q = res.size();

    if (res.size() % 2 == 1)
        return res[res.size() / 2];
    else
        return (res[res.size() / 2] + res[res.size() / 2 - 1]) / 2;
    return 1;
}

// Method 2
int upperBound(vector<int> &mat, int x, int n)
{
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mat[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &mat, int n, int m, int mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += upperBound(mat[i], mid, m);
    return cnt;
}

int median(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int low = INT_MAX;
    int high = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }

    int req = (n * m) / 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(mat, n, m, mid);

        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}