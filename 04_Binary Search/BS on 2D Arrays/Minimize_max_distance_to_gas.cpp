#include <bits/stdc++.h>
using namespace std;

int noOfGasStationsReq(vector<int>&stations,long double dist)
    {
        int cnt = 0;
        for(int i=1 ;i<stations.size() ;i++)
        {
            int noInBetween = ((stations[i] - stations[i-1])/dist);
            if(stations[i] - stations[i-1]/dist == noInBetween * dist)
                noInBetween--;
            cnt += noInBetween;
        }
        return cnt;
    }
  
    double findSmallestMaxDist(vector<int> &stations, int k) 
    {
        int n = stations.size();
        long double low = 0;
        long double high = 0;
        
        for(int i=0 ;i<n-1 ;i++)
            high = max(high,(long double)(stations[i+1]-stations[i]));
        
        long double diff = 1e-6;
        
        while(high - low > diff)
        {
            long double mid = (low + high)/(2.0);
            int cnt = noOfGasStationsReq(stations,mid);
            if(cnt > k)
                low = mid;
            else
                high = mid;
        }
        return high;
    }