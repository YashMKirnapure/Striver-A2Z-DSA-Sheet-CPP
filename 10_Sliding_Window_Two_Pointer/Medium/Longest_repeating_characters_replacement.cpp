#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string str, int k)
{
    int n = str.size();
    int maxlen = 0;
    int len = 0;
    int maxf = 0;
    int left = 0;
    int right = 0;
    vector<int> count(26, 0);

    while (right < n)
    {
        count[str[right] - 'A']++;
        maxf = max(maxf, count[str[right] - 'A']);

        if ((right - left + 1) - maxf <= k)
        {
            len = right - left + 1;
            maxlen = max(maxlen, len);
        }
        else
        {
            count[str[left] - 'A']--;
            left++;
        }
        right++;
    }
    return maxlen;
}