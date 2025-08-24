#include <iostream>
#include <map>
using namespace std;

int romanToInt(string s) 
    {
        int n = s.size();
        map <char,int> mp;
        mp['I'] = 1;        
        mp['V'] = 5;        
        mp['X'] = 10;        
        mp['L'] = 50;        
        mp['C'] = 100;        
        mp['D'] = 500;        
        mp['M'] = 1000;        
        int res = 0;

        for(int i=0 ;i<n ;i++)
        {
            if(mp[s[i]] < mp[s[i+1]])
                res = res - mp[s[i]];
            else
                res = res + mp[s[i]];
        }
        return res;
    }