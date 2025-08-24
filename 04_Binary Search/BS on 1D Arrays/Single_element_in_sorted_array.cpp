#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr) 
    {
        int n = arr.size();
        int low = 0;
        int high = n-1;

        if(n == 1)
            return arr[0];

        while(low < high)
        {
            int mid = (low + high)/2;
            if(arr[low]!=arr[low+1])
                return arr[low];
            else if(arr[high]!=arr[high-1])
                return arr[high];
            else if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1])
                return arr[mid];
            else
            {
                low = low + 2;
                high = high - 2;
            }
        }
        return 1;
    }