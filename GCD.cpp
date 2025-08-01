#include <bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2)
{
    if (n1 == n2)
        return n1;

    if (n1 > n2)
        return gcd(n1 - n2, n2);
    else
        return gcd(n1, n2 - n1);
}