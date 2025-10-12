#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    int sz = tasks.size();
    vector<int> mp(26, 0);
    priority_queue<int> pq;
    vector<int> res;
    int time = 0;

    for (char &x : tasks)
        mp[x - 'A']++;

    for (int i = 0; i < 26; i++)
    {
        if (mp[i] > 0)
            pq.push(mp[i]);
    }

    while (!pq.empty())
    {
        vector<int> temp;
        for (int i = 1; i <= n + 1; i++)
        {
            if (!pq.empty())
            {
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }
        for (int &f : temp)
        {
            if (f > 0)
                pq.push(f);
        }

        if (pq.empty())
            time += temp.size();
        else
            time += n + 1;
    }
    return time;
}