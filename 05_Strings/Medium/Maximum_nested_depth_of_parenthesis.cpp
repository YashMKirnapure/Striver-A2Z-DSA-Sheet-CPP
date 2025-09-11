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

/*
1. Initialize counters
    cnt → keeps track of the current depth.
    maxy → stores the maximum depth seen so far.
2. Traverse the string
    If we see '(' → increase cnt (we just went one level deeper).
    If we see ')' → decrease cnt (we closed one level, so we go back up).
    After every change, update maxy = max(maxy, cnt).
3. Final answer
    maxy holds the deepest nesting level.
*/