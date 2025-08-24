#include <bits/stdc++.h>
using namespace std;

// Method 1
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    for (int i = 0; i < n; i++)
    {
        int low = 0;
        int high = m - 1;
        
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[i][mid] == target)
            return true;
            else if (matrix[i][mid] > target)
            high = mid - 1;
            else
            low = mid + 1;
        }
    }
    return false;
}

// Method 2
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int row = 0;
    int col = m - 1;

    while (col >= 0 && row < n)
    {
        if (matrix[row][col] > target)
            col--;
        else if (matrix[row][col] < target)
            row++;
        else if (matrix[row][col] == target)
            return true;
    }
    return false;
}