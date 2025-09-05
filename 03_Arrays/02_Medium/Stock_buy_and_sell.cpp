#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxProf = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProf = max(maxProf, prices[i] - minPrice);
    }
    return maxProf;
}

/*
Logic:

Track two key values:

minPrice = lowest stock price seen so far (best buying opportunity)
maxProf = maximum profit achievable so far


Process each day's price:

Update minimum price - If today's price is lower than previous minimum, update it (better buying opportunity)
Calculate potential profit - If we bought at the lowest price seen so far and sold today, what would be the profit?
Update maximum profit - Keep track of the best profit opportunity encountered


Key insight - For each day, we consider:

"What if I sell today?" (using the best buying price from all previous days)
"Is today a better day to buy for future selling?"


Single pass optimization - We don't need to check all buy-sell combinations; just track the minimum buying price as we go.

Example:

Input: [7,1,5,3,6,4]
Process:

Day 0 (price=7): minPrice=7, maxProf=0
Day 1 (price=1): minPrice=1, maxProf=0
Day 2 (price=5): minPrice=1, maxProf=4 (buy at 1, sell at 5)
Day 3 (price=3): minPrice=1, maxProf=4
Day 4 (price=6): minPrice=1, maxProf=5 (buy at 1, sell at 6)
Day 5 (price=4): minPrice=1, maxProf=5


Result: 5 (buy at price 1, sell at price 6)

Time Complexity: O(n) - single pass
Space Complexity: O(1) - only two variables
Key insight: We only need to remember the cheapest price seen so far, and for each current price, calculate if selling now would give us the best profit.
*/