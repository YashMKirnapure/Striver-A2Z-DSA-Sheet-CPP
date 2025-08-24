#include <iostream>
using namespace std;

int maxDepth(string str)
{
    int n = str.size();
    int maxy = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            cnt++;
        else if (str[i] == ')')
            cnt--;
        maxy = max(maxy, cnt);
    }
    return maxy;
}