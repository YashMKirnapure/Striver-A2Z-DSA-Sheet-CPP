#include <bits/stdc++.h>
using namespace std;

  bool isPossible(vector<int>&arr,int students,int pages)
    {
        int cntStu = 1;
        int n = arr.size();
        int sum = 0;
        
        for(int i=0 ;i<n ;i++)
        {
            if(arr[i] > pages)
                return false;
            if(sum + arr[i] > pages)
            {
                cntStu++;
                sum = arr[i];
                if(cntStu > students)
                    return false;
            }
            else
            {
                sum += arr[i];
            }
        }
        return true;
    }
  
    int findPages(vector<int> &arr, int students) 
    {
        int n = arr.size();
        int ans = -1;
        
        if(students > n)
            return ans;
            
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(isPossible(arr,students,mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }