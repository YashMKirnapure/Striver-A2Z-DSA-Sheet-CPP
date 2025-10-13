#include <iostream>
#include <queue>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (pq1.empty() || num < pq1.top())
            pq1.push(num);
        else
            pq2.push(num);

        // Always maintain max heap size pq1 size one greater than min heap pq2 size or both size must be equal
        if (abs((int)pq1.size() - (int)pq2.size()) > 1)
        {
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if (pq1.size() < pq2.size())
        {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }

    double findMedian()
    {
        if (pq1.size() == pq2.size())
            return (pq1.top() + pq2.top()) / 2.0;
        return pq1.top();
    }
};