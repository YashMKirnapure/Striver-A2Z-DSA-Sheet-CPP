#include <iostream>
#include <list>
#include <deque>
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

int pageFaults(int N, int C, int pages[])
{
    list<int> cache;
    unordered_map<int, list<int>::iterator> pos;

    int pagefault = 0;

    for (int i = 0; i < N; i++)
    {
        auto it = pos.find(pages[i]);

        if (it == pos.end())
        {
            pagefault++;

            if ((int)cache.size() == C)
            {
                int lru = cache.front();
                cache.pop_front();
                pos.erase(lru);
            }
            cache.push_back(pages[i]);
            pos[pages[i]] = prev(cache.end());
        }
        else
        {
            cache.erase(it->second);
            cache.push_back(pages[i]);
            pos[pages[i]] = prev(cache.end());
        }
    }
    return pagefault;
}

int pageFaults(int N, int C, int pages[])
{
    int pagefault = 0;
    deque<int> cache;
    unordered_set<int>present;

    for (int i = 0; i < N; i++)
    {
        int page = pages[i];

        if(present.find(page) == present.end())
        {
            pagefault++;
            if((int)cache.size() == C)
            {
                int lru = cache.front();
                cache.pop_front();
                present.erase(lru);
            }
            cache.push_back(page);
            present.insert(page);
        }
        else
        {
            auto it = find(cache.begin(), cache.end(), page);
            cache.erase(it);
            cache.push_back(page);
        }
    }
    return pagefault;
}