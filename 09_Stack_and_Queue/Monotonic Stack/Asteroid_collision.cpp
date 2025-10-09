#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n = asteroids.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (asteroids[i] > 0)
            st.push(asteroids[i]);
        else
        {
            while (!st.empty() && st.top() < -asteroids[i] && st.top() > 0)
            {
                if (abs(asteroids[i]) > st.top())
                    st.pop();
            }
            if (st.empty() || st.top() < 0)
                st.push(asteroids[i]);
            if (!st.empty() && st.top() == abs(asteroids[i]))
                st.pop();
        }
    }

    vector<int> res(st.size());
    int i = st.size() - 1;

    while (!st.empty())
    {
        res[i--] = st.top();
        st.pop();
    }
    return res;
}

/*
1. Use a stack to simulate asteroid movement.

2. If current asteroid moves right (>0), push it.

3. If it moves left (<0):
    Pop smaller right-moving asteroids (st.top() < |current|).
    If stack empty or top is left-moving, push current.
    If top equals |current|, both destroy each other.

4. Finally, stack contains surviving asteroids in order.
*/