#include <bits/stdc++.h>
using namespace std;

int noOfGasStationsReq(vector<int> &stations, long double dist)
{
    int cnt = 0;
    for (int i = 1; i < stations.size(); i++)
    {
        int noInBetween = ((stations[i] - stations[i - 1]) / dist);
        if (stations[i] - stations[i - 1] / dist == noInBetween * dist)
            noInBetween--;
        cnt += noInBetween;
    }
    return cnt;
}

double findSmallestMaxDist(vector<int> &stations, int k)
{
    int n = stations.size();
    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++)
        high = max(high, (long double)(stations[i + 1] - stations[i]));

    long double diff = 1e-6;

    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = noOfGasStationsReq(stations, mid);
        if (cnt > k)
            low = mid;
        else
            high = mid;
    }
    return high;
}

/*
🔹 noOfGasStationsReq(stations, dist)

For every consecutive pair of stations:

Check the gap between them.

Figure out how many extra stations are needed so that no segment is longer than dist.

Formula:

noInBetween = (stations[i] - stations[i-1]) / dist


(essentially splitting the gap into parts of length ≤ dist).

Adjust edge case if it divides evenly.

Return total new stations required.

🔹 findSmallestMaxDist(stations, k)

Search space:

low = 0.

high = max distance between consecutive stations.

Binary search on answer (distance):

mid = (low + high) / 2.

Count how many new stations would be needed if the max distance allowed is mid.

If more than k → mid is too small, so increase low.

Else → feasible, shrink high.

Stop when precision ≤ 1e-6 → high gives the minimized maximum distance.
*/