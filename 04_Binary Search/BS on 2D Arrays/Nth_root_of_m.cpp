#include <iostream>
using namespace std;

int nthRoot(int n, int m) 
    {
        int low = 0;
        int high = m;
        
        if(n == 1)  
            return m;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            int prod = 1;
            int dummy = n;
            
            while(n--)
                prod = prod * mid;
            n = dummy;
            
            if(prod == m)
                return mid;
            else if((low == mid || high == mid) && prod < m)
                return -1;
            else if(prod > m)
                high = mid;
            else
                low = mid;
        }
        return -1;
    }