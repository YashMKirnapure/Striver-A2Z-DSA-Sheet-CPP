#include <bits/stdc++.h>
using namespace std;

int max_ele(vector<int>&bloomDay)
    {
        int maxy = INT_MIN;
        int n = bloomDay.size();

        for(int x : bloomDay)
            maxy = max(maxy,x);
        return maxy;
    }

    bool canMake(vector<int>&bloomDay,int m,int k,int mid)
    {
        int bouquets = 0;
        int flowers = 0;
        int n = bloomDay.size();

        for(int i=0 ;i<n ;i++)
        {
            if(bloomDay[i] <= mid)
            {
                flowers++;
                if(flowers == k)
                {
                    bouquets++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();
        long long totalFlowers = 1LL * m * k;

        if(totalFlowers > n)
            return -1;

        int low = 1;
        int high = max_ele(bloomDay);
        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(canMake(bloomDay,m,k,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }