#include <iostream>
#include <unordered_map>
using namespace std;

int beautySum(string str) 
    {
        int n = str.size();
        int sum = 0;

        for(int i=0 ;i<n ;i++)
        {
            unordered_map <char,int> mp;
            for(int j=i ;j<n ;j++)
            {
                mp[str[j]]++;
                int maxy = 0;
                int miny = INT_MAX;

                for(auto &x : mp)
                {
                    maxy = max(maxy,x.second);
                    miny = min(miny,x.second);
                }
                sum = sum + (maxy - miny);
            }
        }
        return sum;
    }