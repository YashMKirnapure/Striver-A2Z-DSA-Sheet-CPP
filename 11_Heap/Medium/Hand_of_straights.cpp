#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    int n = hand.size();
    map<int, int> mp;

    if (n % groupSize != 0)
        return false;

    for (int i = 0; i < n; i++)
    {
        mp[hand[i]]++;
    }

    while (!mp.empty())
    {
        int curr = mp.begin()->first; //.second : frequency
        // curr+1,curr+2,curr+3....,curr+k
        for (int i = 0; i < groupSize; i++)
        {
            if (mp[curr + i] == 0)
                return false;
            mp[curr + i]--;
            if (mp[curr + i] == 0)
                mp.erase(curr + i);
        }
    }
    return true;
}