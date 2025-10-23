#include <iostream>
using namespace std;

bool hasSameDigits(string s)
{
    while (s.size() > 2)
    {
        string temp;
        for (int i = 0; i + 1 < s.size(); i++)
        {
            int n1 = s[i] - '0';
            int n2 = s[i + 1] - '0';

            int newNum = (n1 + n2) % 10;
            temp += (newNum + '0');
        }
        s = temp;
    }
    return s[0] == s[1];
}
