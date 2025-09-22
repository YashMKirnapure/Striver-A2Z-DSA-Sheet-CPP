#include <iostream>
using namespace std;

long long func(long long x, long long n)
{
    long long mod = 1e9 + 7;
    if (n == 0)
        return 1;

    long long half = func(x, n / 2);
    long long res = (half * half) % mod;

    if (n % 2 == 1)
        res = (res * x) % mod;

    return res;
}

int countGoodNumbers(long long n)
{
    long long mod = 1e9 + 7;
    long long evenPlaces = (n + 1) / 2;
    long long oddPlaces = n / 2;

    return (long long)(func(5, evenPlaces) * func(4, oddPlaces)) % mod;
}

/*
We need to count the number of good digit strings of length n, where:
    Even indices (0,2,4,...) → must be chosen from {0,2,4,6,8} → 5 choices
    Odd indices (1,3,5,...) → must be chosen from prime digits {2,3,5,7} → 4 choices
So:
    Number of ways for even positions = 5^{(\text{#even places})}
    Number of ways for odd positions = 4^{(\text{#odd places})}
    Total = product of both (mod 10^9 + 7)

Step 1: Split positions
    If n = 5,
        Even places = 3 (indices 0,2,4)
        Odd places = 2 (indices 1,3)
That’s why:
    long long evenPlaces = (n+1)/2; // ceiling of n/2
    long long oddPlaces = n/2;      // floor of n/2

Step 2: Modular exponentiation
The helper function func(x,n) calculates 𝑥^𝑛 mod (1e9+7) efficiently using binary exponentiation:
1.Base case: if n == 0, return 1.
2.Compute half = func(x, n/2) recursively.
3.Square it: res = (half * half) % mod.
4.If n is odd → multiply one more x.

This reduces exponentiation from O(n) → O(log n).

Step 3: Final formula
total = (5^evenPlaces * 4^oddPlaces) % mod;
*/