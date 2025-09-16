#include <bits/stdc++.h>
using namespace std;

// Method 1
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head->next == NULL && n == 1)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    if (fast == NULL)
        return head->next;

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode *delNode = slow->next;
    slow->next = slow->next->next;
    delete (delNode);
    return head;
}

// Method 2
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head->next == NULL && n == 1)
        return NULL;

    ListNode *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    int stop = cnt - n;
    int i = 1;

    if (stop == 0)
    {
        head = head->next;
        return head;
    }

    temp = head;

    while (i != stop)
    {
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
    return head;
}

/*
1. If the list has only one node and we need to remove it → return NULL.
2. Use two pointers (fast and slow), both starting at head.
3. Move fast ahead by n steps.
    If fast becomes NULL, it means the node to remove is the head, so return head->next.
4. Move both slow and fast until fast reaches the last node.
    At this point, slow is just before the node to be deleted.
5. Delete the node (slow->next) safely, and adjust links.
6. Return updated head.
*/