#include <bits/stdc++.h>
using namespace std;

string armstrongNumber(int n)
{
    string ans = "false";
    int tmp = n;
    int Numb = 0;
    int sum = 0;
    
    while (n > 0)
    {
        Numb = n % 10;
        sum = sum + pow(Numb, 3);
        n = n / 10;
    }
    if (sum == tmp)
        ans = "true";
    return ans;
}
