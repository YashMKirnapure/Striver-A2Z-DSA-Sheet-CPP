#include <iostream>
using namespace std;

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    if (head == NULL || head->next == NULL)
        return false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

/*
1.Use two pointers:
    slow moves 1 step at a time.
    fast moves 2 steps at a time.

2.If there’s a cycle, slow and fast will eventually meet inside the loop.

3.If fast reaches NULL (end of list), no cycle exists.
*/