#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPlatform(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int cnt = 0;
    int res = -1;
    int i = 0;
    int j = 0;

    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            cnt++;
            res = max(res, cnt);
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
    }
    return res;
}