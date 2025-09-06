#include <iostream>
#include <vector>
using namespace std;

// You want to find the first index where the element is greater than x.
int upperBound(vector<int>&arr,int x)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// int ub = upper_bound(arr.begin(),arr.end(),x) - arr.begin();