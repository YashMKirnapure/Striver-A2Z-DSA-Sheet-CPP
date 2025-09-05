#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int j = 0; j < m; j++)
    {
        reverse(matrix[j].begin(), matrix[j].end());
    }
}

/*
Step-by-step explanation of your code:

Transpose the matrix

The first nested loop swaps matrix[i][j] with matrix[j][i] for j > i.

This flips the matrix over its diagonal.

Example:

1 2 3        1 4 7
4 5 6   →    2 5 8
7 8 9        3 6 9


Reverse each row

After transposing, the matrix still isn’t rotated yet.

The second loop reverses every row.

Example:

1 4 7        7 4 1
2 5 8   →    8 5 2
3 6 9        9 6 3


Now it’s a proper 90° clockwise rotation
*/