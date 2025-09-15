#include <iostream>
using namespace std;

ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;

    if (head == NULL || head->next == NULL)
        return head;

    while (curr != NULL)
    {
        ListNode *front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

/*
1.Edge cases:
    If the list is empty (head == NULL) or has only one node, just return head (nothing to reverse).

2.Setup:
    curr → pointer to the current node you’re processing (starts at head).
    prev → pointer to the previous node (starts as NULL because new tail will point to NULL).

3.Iterate and reverse links:
    Save the next node: front = curr->next.
    Reverse the link: curr->next = prev.
    Move prev forward: prev = curr.
    Move curr forward: curr = front.

4.End condition:
    When curr becomes NULL, the list is fully reversed. 
    prev will be pointing at the new head, so return it.
*/