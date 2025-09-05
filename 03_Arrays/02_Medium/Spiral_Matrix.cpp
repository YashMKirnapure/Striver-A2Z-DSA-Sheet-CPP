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

/*
Step-by-step explanation:

Initialize boundaries

top = 0 → starting row

bottom = n - 1 → ending row

left = 0 → starting column

right = m - 1 → ending column

These four variables define the current “layer” of the spiral.

Loop until boundaries overlap

Continue while top <= bottom and left <= right.

Traverse in 4 directions
Each spiral "lap" has 4 steps:

(a) Left → Right (top row)

Go across row top from column left to right.

Then move boundary down: top++.

(b) Top → Bottom (right column)

Go down column right from row top to bottom.

Then move boundary left: right--.

(c) Right → Left (bottom row, if still valid)

Go across row bottom from column right to left.

Then move boundary up: bottom--.

(d) Bottom → Top (left column, if still valid)

Go up column left from row bottom to top.

Then move boundary right: left++.

Repeat until the boundaries cross (all elements are visited).
*/