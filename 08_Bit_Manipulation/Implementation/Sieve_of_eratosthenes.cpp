#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n)
{
    int cnt = 0;
    vector<bool> prime(n , true);
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i*i < n; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (prime[i]) cnt++;
    }
    return cnt;
}

/*
1. Start by assuming all numbers ≥ 2 are prime.

2. Begin with the smallest prime 2. Eliminate all multiples of 2 (except 2 itself).

3. Move to the next number that’s still marked prime (3). Eliminate all multiples of 3.

4. Continue this for all numbers up to √n.
(Because any composite number ≤ n must have a factor ≤ √n.)

5. After the elimination, the numbers still marked prime are your actual primes.

6. Count them (or list them, depending on the problem).
*/