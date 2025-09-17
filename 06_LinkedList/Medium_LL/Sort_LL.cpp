#include <iostream>
using namespace std;

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    temp->next = NULL;

    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);

    return mergelist(l1, l2);
}

ListNode *mergelist(ListNode *l1, ListNode *l2)
{
    ListNode *ptr = new ListNode(0);
    ListNode *curr = ptr;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    if (l1 != NULL)
    {
        curr->next = l1;
        l1 = l1->next;
    }

    if (l2 != NULL)
    {
        curr->next = l2;
        l2 = l2->next;
    }
    return ptr->next;
}

/*
1. Base case:
    If the list is empty (NULL) or has just one node → already sorted → return head.

2. Split the list into halves:
    Use slow & fast pointers:
        slow moves one step at a time.
        fast moves two steps at a time.
    When fast reaches the end, slow is at the middle.
    Use a temp pointer to cut the list into two halves.

3. Recursive Sort:
    Recursively call sortList on each half (l1 and l2).

4. Merge two sorted halves:
    Use the helper function mergelist.
    Compare nodes from l1 and l2 one by one.
    Append the smaller one to the merged list.
    Continue until one list is exhausted.
    Attach the remaining nodes.

5. Return the merged head as the final sorted list.
*/