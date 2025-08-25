#include <iostream>
using namespace std;

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    unordered_map<ListNode *, int> vis;

    for (ListNode *curr = head; curr != NULL; curr = curr->next)
    {
        if (vis[curr] > 1)
            return curr;
        vis[curr]++;
    }
    return NULL;
}
