#include <iostream>
#include <vector>
using namespace std;

int getSecondLargest(vector<int> &arr)
{
    int n = arr.size();
    int maxy = INT_MIN;
    int sMaxy = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxy)
        {
            sMaxy = maxy;
            maxy = arr[i];
        }
        else if (arr[i] > sMaxy && arr[i] != maxy)
        {
            sMaxy = arr[i];
        }
    }

    if (sMaxy == INT_MIN)
        return -1;

    return sMaxy;
}