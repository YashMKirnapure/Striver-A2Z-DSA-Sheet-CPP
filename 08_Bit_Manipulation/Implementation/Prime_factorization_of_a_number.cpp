#include <iostream>
#include <vector>
using namespace std;

vector<int> findPrimeFactors(int N)
{
    vector<int> spf(N + 1, 0);

    for (int i = 2; i <= N; i++)
        spf[i] = i;

    for (int i = 2; i * i <= N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    vector<int> ans;
    int i = 0;

    while (N > 1)
    {
        i = spf[N];
        N = N / i;
        ans.push_back(i);
    }
    return ans;
}

/*
1. Build the SPF array (Smallest Prime Factor):
    For every number i from 2 to N, initialize spf[i] = i (assume it’s prime).
    Then, for each prime i, update its multiples with the smallest prime that divides them.
    So, after this step, spf[x] tells you the smallest prime factor of x.

2. Use SPF to factorize N quickly:
    Keep dividing N by its smallest prime factor (spf[N]).
    Record that factor.
    Repeat until N = 1.

3. The result is the prime factorization of N in ascending order.
*/

