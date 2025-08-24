#include <iostream>
#include <vector>
using namespace std;

int countFreq(vector<int>& arr, int target) 
    {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int cnt = 0;
        
        int first = -1;
        int last = -1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
        
            if(arr[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        low = 0;
        high = n-1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(arr[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        if(first == -1 && last == -1)   
            return 0;
        if((first == -1 && last != -1) || (first != -1 && last == -1))
            return 1;
        return last - first + 1;
    }