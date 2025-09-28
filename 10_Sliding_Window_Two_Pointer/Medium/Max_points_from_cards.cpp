#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int> &arr, int k)
{
    int n = arr.size();
    int lsum = 0;
    int rsum = 0;
    int sum = 0;

    for (int i = 0; i < k; i++)
        lsum += arr[i];

    sum = max(sum, lsum);
    int ridx = n - 1;

    for (int i = k - 1; i >= 0; i--)
    {
        lsum = lsum - arr[i];
        rsum = rsum + arr[ridx];
        ridx--;
        sum = max(sum, lsum + rsum);
    }
    return sum;
}