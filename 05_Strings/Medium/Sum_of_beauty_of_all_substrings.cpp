#include <iostream>
#include <unordered_map>
using namespace std;

int beautySum(string str)
{
    int n = str.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int freq[26] = {0};

        for (int j = i; j < n; j++)
        {
            freq[str[j] - 'a']++;

            int maxy = 0, miny = INT_MAX;

            for (int k = 0; k < 26; k++)
            {
                if (freq[k] > 0)
                {
                    maxy = max(maxy, freq[k]);
                    miny = min(miny, freq[k]);
                }
            }

            sum += (maxy - miny);
        }
    }
    return sum;
}

/*
1. Loop over all starting indices i.

2. For each i, expand the substring by moving j from i to end.

3. Maintain a frequency array freq[26] and update it as str[j] is added.

4. After each update, find the max frequency and min frequency (nonzero) among characters.

5. Add (max - min) to the running sum.

6. Return the final sum after processing all substrings.
*/