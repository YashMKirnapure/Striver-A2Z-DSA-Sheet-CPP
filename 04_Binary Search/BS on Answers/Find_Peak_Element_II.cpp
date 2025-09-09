#include <bits/stdc++.h>
using namespace std;

int maxEleIdx(vector<vector<int>> &mat, int n, int m, int col)
{
    int maxVal = -1;
    int idx = -1;

    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > maxVal)
        {
            maxVal = mat[i][col];
            idx = i;
        }
    }
    return idx;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> res;

    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = maxEleIdx(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;
        if (mat[row][mid] > left && mat[row][mid] > right)
            return {row, mid};
        else if (mat[row][mid] < left)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, -1};
}

/*
We do binary search on columns instead of rows.

low = 0, high = m-1

At each step, pick mid column.

In that column, find the maximum element’s row index using maxEleIdx.

This ensures we’re always considering the “most promising candidate” in that column.

Check neighbors:

left → element just before it in the same row (if exists).

right → element just after it in the same row (if exists).

Peak condition:

If mat[row][mid] > left && mat[row][mid] > right → we found the peak.

Otherwise, move search direction:

If mat[row][mid] < left → move left (high = mid - 1).

Else → move right (low = mid + 1).

If its left/right neighbor is bigger, the peak must lie in that half.
*/