#include <bits/stdc++.h>
using namespace std;

string lexSmallest(string s) 
    {
        string temp = s;
        int n = s.size();
        priority_queue<string,vector<string>,greater<string>>pq;
        
        for(int k=1 ;k<=n ;k++)
        {
            reverse(temp.begin(),temp.begin()+k);
            if(s > temp)
                pq.push(temp);

            reverse(temp.begin()+k,temp.end());
            if(s > temp)
                pq.push(temp);
        }
        return pq.top();
    }©leetcode