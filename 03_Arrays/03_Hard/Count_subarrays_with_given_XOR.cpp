#include <bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int cnt = 0;
    int Xor = 0;

    for (int i = 0; i < n; i++)
    {
        Xor = Xor ^ arr[i];
        if (Xor == k)
            cnt++;
        if (mp.find(Xor ^ k) != mp.end())
            cnt += mp[Xor ^ k];
        mp[Xor]++;
    }
    return cnt;
}