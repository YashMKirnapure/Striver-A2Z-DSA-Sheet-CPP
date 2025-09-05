#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> mat(numRows);
    int n = mat.size();
    int m = mat[0].size();
    mat[0] = {1};

    if (numRows == 1)
        return mat;

    for (int i = 1; i < n; i++)
    {
        mat[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i - 1][j] + mat[i - 1][j - 1];
        }
    }
    return mat;
}

/*
Step-by-step explanation:

Initialize the structure

Create a 2D vector mat with numRows rows.

First row (mat[0]) is always {1}.

Example (for numRows = 1):
1


Special case: only 1 row

If numRows == 1, just return [[1]].

Build triangle row by row

For each row i (from 1 to numRows - 1):

Resize the row to i+1 elements (since row i has i+1 numbers).

For each column j (from 0 to i):

If it’s the first element (j == 0) or the last element (j == i) → set it to 1.

Otherwise → each element is the sum of the two numbers above it:

mat[i][j] = mat[i-1][j] + mat[i-1][j-1]


Return the matrix

After filling, return the completed Pascal’s Triangle.
*/