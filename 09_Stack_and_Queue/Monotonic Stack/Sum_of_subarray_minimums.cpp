#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NSE(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> res(n, n - 1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}

vector<int> PSE(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    int total = 0;
    int m = 1e9 + 7;

    vector<int> pse = PSE(arr);
    vector<int> nse = NSE(arr);

    for (int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;

        total = (total + (left * right * 1LL * arr[i]) % m) % m;
    }
    return total;
}

/*
1. It finds for each element how far left and right it can stretch without finding a smaller number.

2. Multiplies those two counts to know how many subarrays it’s the minimum in.

3. Then multiplies that count with the element’s value.

4. Adds it all up (with a modulo to keep the number small).
*/