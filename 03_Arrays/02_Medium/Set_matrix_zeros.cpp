#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();    // no of rows
    int m = matrix[0].size(); // no of cols

    vector<bool> rows(n, false);
    vector<bool> cols(m, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rows[i] || cols[j])
                matrix[i][j] = 0;
        }
    }
}

/*
Step-by-step explanation:

Find the matrix dimensions

n = number of rows

m = number of columns

Keep track of rows & columns that should become zero

Create a boolean array rows of size n (all initialized false).

Create a boolean array cols of size m (all initialized false).

First pass: Identify which rows and columns need to be zeroed

Traverse the matrix cell by cell.

If you encounter matrix[i][j] == 0:
→ mark rows[i] = true
→ mark cols[j] = true

This records which row and column must later be set entirely to 0.

Second pass: Update the matrix

Traverse the matrix again.

For each cell (i, j):

If its row is marked zero (rows[i] == true) OR its column is marked zero (cols[j] == true),
→ set matrix[i][j] = 0.
*/