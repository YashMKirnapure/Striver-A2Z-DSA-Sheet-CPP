#include <iostream>
#include <vector>
using namespace std;

int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    int top = 0;
    int down = n - 1;

    if (n == 1)
        return 0;

    while (top < down)
    {
        if (mat[top][down] == 1)
            top = top + 1;
        else if (mat[down][top] == 1)
            down = down - 1;
        else
        {
            top++;
            down--;
        }
    }

    if (top > down)
        return -1;

    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;
        if (mat[top][i] == 0 && mat[i][top] == 1)
            continue;
        else
            return -1;
    }
    return top;
}

/*
1. A celebrity is someone who knows no one, but everyone knows them.

2. Use two pointers (top and down) to eliminate non-celebrities:
    If mat[top][down] == 1, top knows down → top cannot be a celebrity → move top++.
    Else if mat[down][top] == 1, down knows top → down cannot be a celebrity → move down--.
    Repeat until one potential candidate remains.

3. Verify that the candidate:
    Knows no one (mat[cand][i] == 0 for all i ≠ cand), and
    Is known by everyone (mat[i][cand] == 1 for all i ≠ cand).

4. If both conditions hold, return that index; else return -1.

⏱ Time Complexity: O(n) elimination + O(n) verification = O(n).
*/