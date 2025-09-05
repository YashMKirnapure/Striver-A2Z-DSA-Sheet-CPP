#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> &arr)
{
    int n = arr.size();
    int hash[n + 1] = {0};

    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    int repeating = -1;
    int missing = -1;

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            repeating = i;
        else if (hash[i] == 0)
            missing = i;
        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

/*
Step-by-step logic:

Initialize a frequency array (hash).

Create an array hash[n+1] and set all counts to 0.

This will track how many times each number 1...n occurs.

Count occurrences.

Loop through the input array arr.

For each number arr[i], increment its count in hash.

Find repeating and missing.

Loop through 1...n:

If hash[i] == 2 → that number is repeating.

If hash[i] == 0 → that number is missing.

Stop early if both are found.

Return results.
*/

// Method - 2
vector<int> findTwoElement(vector<int> &arr) {
    long long n = arr.size();

    long long S = (n * (n + 1)) / 2;                // expected sum
    long long S2 = (n * (n + 1) * (2 * n + 1)) / 6; // expected sum of squares

    long long Sa = 0, S2a = 0; // actual sum, sum of squares
    for (long long x : arr) {
        Sa += x;
        S2a += (1LL * x * x);
    }

    long long diff = Sa - S;       // R - M
    long long sqDiff = S2a - S2;   // R^2 - M^2 = (R-M)(R+M)

    long long sumRM = sqDiff / diff; // R + M

    long long R = (diff + sumRM) / 2;
    long long M = R - diff;

    return {(int)R, (int)M};
}


