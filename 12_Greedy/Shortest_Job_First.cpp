#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(vector<int> &bt)
{
    int n = bt.size();
    sort(bt.begin(), bt.end());
    long long sum = 0;
    long long wt = 0;

    for (int i = 0; i < n; i++)
    {
        wt = wt + sum;
        sum = sum + bt[i];
    }

    return wt / n;
}
