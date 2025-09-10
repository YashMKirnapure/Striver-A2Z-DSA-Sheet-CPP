#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

string convert2Binary(int n)
{
    string res = "";
    while (n > 0)
    {
        if (n % 2 == 1)
            res += '1';
        else
            res += '0';
        n = n / 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

int convert2Decimal(string str)
{
    int n = str.size();
    int res = 0;

    for(int i=n-1 ;i>=0 ;i--)
    {
        res = res + (str[i]-'0') * pow(2,n-1-i);
    }
    return res;
}

int main()
{
    cout<<convert2Binary(10);
    // cout<<convert2Decimal("1011");
}
