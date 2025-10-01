#include <iostream>
#include <vector>
#include <algorithm>
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

/*
1. Start checking numbers from 1 up to √n.
    If a number i divides n evenly, then both i and n/i are divisors.
    Example: if n = 36 and i = 6, then 36 ÷ 6 = 6. Since it’s the same, we only add it once.

2. Store all these divisors in a list.
    While looping, you’re effectively finding both the small divisor (i) and the matching large divisor (n/i).

3. After the loop, sort the list so divisors come out in increasing order.

4. Print them all.
*/