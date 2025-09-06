#include <iostream>
#include <vector>
using namespace std;

// You want to find the first index where the element is greater than or equal to x.
int lowerBound(vector<int>&arr,int x)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1; //look for more small index on left
        }
        else
            low = mid + 1;
    }
    return ans;
}

// int lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
