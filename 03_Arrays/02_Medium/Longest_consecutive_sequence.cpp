#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
    {
        int cnt = 0;
        int res = 1;
        int lastSmaller = INT_MIN;
        sort(arr,arr+N);
        
        for(int i=0 ;i<N ;i++)
        {
            if(arr[i]-1 == lastSmaller)
            {
                cnt = cnt + 1;
                lastSmaller = arr[i];
            }
            else if(arr[i] != lastSmaller)
            {
                lastSmaller = arr[i];
                cnt = 1;
            }
            res = max(res,cnt);
        }
        return res;
    }