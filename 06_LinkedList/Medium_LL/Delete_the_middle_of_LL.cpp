#include <bits/stdc++.h>
using namespace std;

// Method 1
ListNode *deleteMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *temp = NULL;

    if (head->next == NULL)
        return NULL;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // even length LL scenario
    if (fast->next != NULL)
    {
        slow->next = slow->next->next;
        return head;
    }

    // odd length LL scenario
    if (fast->next == NULL)
    {
        temp->next = slow->next;
        return head;
    }
    return NULL;
}

// Method 2
ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    ListNode *prev = NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}

/*
1. If the list has 0 or 1 node, just return NULL (because after deletion nothing remains).

2. Use two pointers:
    slow moves one step at a time.
    fast moves two steps at a time.
    This ensures that when fast reaches the end, slow is at the middle.

3. Keep track of the node just before slow using prev.

4. When the loop ends:
    slow points to the middle node.
    prev points to the node just before it.

5. Delete the middle node

6. Return the updated head.
*/