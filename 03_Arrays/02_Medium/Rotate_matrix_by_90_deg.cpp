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