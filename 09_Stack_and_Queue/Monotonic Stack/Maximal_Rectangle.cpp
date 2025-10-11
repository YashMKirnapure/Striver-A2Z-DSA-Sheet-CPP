#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;
    stack<int> st;

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxy = 0;
    vector<vector<int>> pSum(rows, vector<int>(cols));

    for (int i = 0; i < cols; i++)
    {
        int sum = 0;
        for (int j = 0; j < rows; j++)
        {
            sum += 1;
            if (matrix[j][i] == '0')
                sum = 0;
            pSum[j][i] = sum;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        maxy = max(maxy, largestRectangleArea(pSum[i]));
    }
    return maxy;
}

/*
1. The problem extends the Largest Rectangle in Histogram idea to a 2D binary matrix.

2. Treat each row as the base of a histogram:
    For every '1', increase the bar height by 1 (accumulating consecutive 1s above).
    For every '0', reset the bar height to 0.

3. After processing each row, use the largestRectangleArea() function (Histogram logic) to find the maximum area for that row’s histogram.

4. The maximum of all these row-wise areas gives the largest rectangle of 1’s in the entire matrix.
*/