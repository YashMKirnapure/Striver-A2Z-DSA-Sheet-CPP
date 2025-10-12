#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

        for (auto list : lists)
        {
            if (list != NULL)
                pq.push(list);
        }

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (!pq.empty())
        {
            ListNode *smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next)
                pq.push(smallest->next);
        }
        return dummy->next;
    }
};