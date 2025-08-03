#include <iostream>
#include <vector>
using namespace std;

int findCeil(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    int ceiL = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ceiL = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ceiL;
}
