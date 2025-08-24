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