#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int right = m - 1;
    int bottom = n - 1;
    int left = 0;
    int top = 0;

    vector<int> ans;

    while (top <= bottom && left <= right)
    {
        // Left to Right
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);
        top++;

        // Top to Bottom
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        if (top <= bottom)
        {
            // Right to Left
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }

        if (left <= right)
        {
            // Bottom to Top
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }
    return ans;
}