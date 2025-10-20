#include <iostream>
using namespace std;

bool checkValidString(string str)
{
    int low = 0;
    int high = 0;
    int n = str.size();

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            low++;
            high++;
        }
        else if (str[i] == ')')
        {
            low--;
            high--;
        }
        else
        {
            low--;
            high++;
        }

        if (low < 0)
            low = 0;
        if (high < 0)
            return false;
    }
    return low == 0;
}