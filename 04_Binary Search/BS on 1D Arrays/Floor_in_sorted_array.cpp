#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int> &arr, int x)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    int flooR = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] <= x)
        {
            flooR = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return flooR;
}
