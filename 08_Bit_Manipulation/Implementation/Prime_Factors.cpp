#include <iostream>
#include <vector>
using namespace std;

vector<int>primeFac(int n)
{
    vector<int> primeFactors;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            primeFactors.push_back(i);
            while (n % i == 0)
                n = n / i;
        }
    }
    if (n != 1)
        primeFactors.push_back(n);
    return primeFactors;
}

/*
1. Start checking numbers from 2 onwards (since 2 is the smallest prime).

2. For each number i, see if it divides n:
    If it does, that means i is a prime factor of n.
    Add i to the list.
    Then, keep dividing n by i until it no longer divides evenly — this makes sure we only record that prime once.

3. Keep moving up until you reach the square root of n.
    Why stop there? Because if n had a factor bigger than its square root, the matching partner factor would already have been found earlier.

4. At the end, if n is not reduced all the way down to 1, then whatever is left is also a prime number, so we add it to the list.
*/