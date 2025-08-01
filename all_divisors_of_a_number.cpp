#include <bits/stdc++.h>
using namespace std;

void print_divisors(int n)
{
    vector<int> res;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (n / i != i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    for (int x : res)
        cout << x << " ";
}
