#include <bits/stdc++.h>
using namespace std;


    bool canPlace(vector<int>&stalls,int k,int dist)
    {
        int cntCows = 1;
        int last = stalls[0];
        int n = stalls.size();
        
        for(int i=1 ;i<n ;i++)
        {
            if(stalls[i] - last >= dist)
            {
                cntCows++;
                last = stalls[i];
            }
        }
        return cntCows >= k;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) 
    {
        int n = stalls.size();
        int ans = -1;
        
        sort(stalls.begin(),stalls.end());
        
        int low = 0;
        int high = (stalls[n-1] - stalls[0]);
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(canPlace(stalls,k,mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }