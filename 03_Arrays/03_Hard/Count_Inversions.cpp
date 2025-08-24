#include <bits/stdc++.h>
using namespace std;

    int merge(vector<int>&arr,int low,int mid,int high)
    {
        int cnt = 0;
        vector<int>temp;
        int left = low;  //starting index of left half of arr
        int right = mid+1; //starting index of right half of arr
        
        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                cnt = cnt + (mid-left+1);
                right++;
            }
        }
        
        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=low ;i<=high ;i++)
        {
            arr[i] = temp[i - low];
        }
        return cnt;
    }
    
    int mergeSort(vector<int>&arr,int low,int high)
    {
        int cnt = 0;
        if(low >= high)
            return cnt;
        int mid = (low + high)/2;
        cnt += mergeSort(arr,low,mid);  //left half
        cnt += mergeSort(arr,mid+1,high); //right half
        cnt += merge(arr,low,mid,high);  //merging sorted halves
        return cnt;
    }
  
    int inversionCount(vector<int> &arr) 
    {
        
        int n = arr.size();
        return mergeSort(arr,0,n-1);
        // return cnt;
    }