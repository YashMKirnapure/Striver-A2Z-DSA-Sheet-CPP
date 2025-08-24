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