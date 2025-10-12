#include <iostream>
#include <stack>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int ind = -1;

    StockSpanner()
    {
        ind = -1;
    }

    // This is basically PGE.
    int next(int price)
    {
        ind = ind + 1;
        int ans = 0;
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        return ans;
    }
};

/*
1. This problem uses the Previous Greater Element (PGE) concept in a streaming fashion.

2. For each new stock price, we want to know how many consecutive days (including today) the price has been less than or equal to today’s price.

3. Maintain a stack of pairs → {price, index}:
    Pop all smaller or equal prices from the stack (they’re “dominated” by the current price).
    The span = current index − index of previous greater element (or ind - (-1) if none exist).
    Push {price, index} onto the stack for future queries.

4. Each price is pushed and popped once, making the solution O(1) on average per query.
*/