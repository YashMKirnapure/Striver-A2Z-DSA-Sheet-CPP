#include <iostream>
#include <vector>
using namespace std;

int height_of_heap(vector<int>&arr)
{
    int n = arr.size();
    int height = 0;

    if(n == 1)
        return 1;

    while(n>1)
    {
        height++;
        n = n/2;
    }
    return height;
}

int main()
{
    vector<int>arr = {1,3,6,5,9,8,10,11};
    cout<<height_of_heap(arr);
}