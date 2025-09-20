#include <iostream>
using namespace std;

ListNode *rotateRight(ListNode *head, int k)
{

    if (head == NULL || head->next == NULL || k == 0)
        return head;

    ListNode *temp = head;
    int len = 1;

    while (temp->next != NULL)
    {
        len++;
        temp = temp->next;
    }

    temp->next = head;
    k = k % len;

    int end = len - k;

    while (end--)
        temp = temp->next;

    head = temp->next;
    temp->next = NULL;

    return head;
}

/*
1.Handle base cases
    Empty list, single node, or k = 0 → no rotation needed.

2.Calculate length and connect end to head
    Traverse the list to find len and the last node temp.
    Make it circular: temp->next = head.

3.Adjust k
    k = k % len → rotation more than length is equivalent to k % len.

4.Find the new tail
    end = len - k → the node that will become the new tail after rotation.
    Move temp end steps forward.

5.Set new head and break the circle
    head = temp->next → new head after rotation
    temp->next = NULL → break circular link

6.Return new head
*/