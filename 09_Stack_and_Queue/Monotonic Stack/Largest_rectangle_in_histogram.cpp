#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NSER(vector<int> &heights)
{
    int n = heights.size();
    vector<int> right(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return right;
}

vector<int> NSEL(vector<int> &heights)
{
    int n = heights.size();
    vector<int> left(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return left;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> nsel = NSEL(heights);
    vector<int> nser = NSER(heights);

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int width = nser[i] - nsel[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}

/*
1. Each bar in the histogram can form a rectangle that extends left and right until a smaller bar blocks it.

2. To find that range efficiently, use two monotonic stacks:
    NSEL (Nearest Smaller to Left): index of previous smaller bar for each element.
    NSER (Nearest Smaller to Right): index of next smaller bar for each element.

3. The width of the rectangle for bar i is right[i] - left[i] - 1.

4. The area is then heights[i] * width.

5. Compute this for every bar and track the maximum area — that’s your largest rectangle in the histogram.
*/