#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] < target)
            low = mid + 1;
        else if (matrix[row][col] > target)
            high = mid - 1;
        else
            return true;
    }
    return false;
}

/*
Matrix is sorted in row-major order:

Each row is sorted.

First element of each row > last element of previous row.

Treat the matrix as a 1D sorted array of length n*m.

Index mid maps to:

Row → mid / m

Col → mid % m

Do binary search like usual.
*/