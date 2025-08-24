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