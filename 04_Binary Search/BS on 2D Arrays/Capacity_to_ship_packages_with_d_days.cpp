#include <bits/stdc++.h>
using namespace std;

int max_ele(vector<int> &weights)
{
    int n = weights.size();
    int maxy = INT_MIN;

    for (int x : weights)
        maxy = max(maxy, x);
    return maxy;
}

int sum_all(vector<int> &weights)
{
    int sum = 0;
    for (int x : weights)
        sum += x;
    return sum;
}

bool canShip(vector<int> &weights, int days, int cap)
{
    int daysNeeded = 1;
    int currLoad = 0;
    int n = weights.size();

    for (int i = 0; i < n; i++)
    {
        if (currLoad + weights[i] > cap)
        {
            daysNeeded++;
            currLoad = 0;
        }
        currLoad += weights[i];
    }
    return daysNeeded <= days;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int low = max_ele(weights);
    int high = sum_all(weights);
    int ans = -1;

    while (low <= high)
    {
        int cap = low + (high - low) / 2;
        if (canShip(weights, days, cap))
        {
            ans = cap;
            high = cap - 1;
        }
        else
        {
            low = cap + 1;
        }
    }
    return ans;
}