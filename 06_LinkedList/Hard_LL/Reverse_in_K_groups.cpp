#include <iostream>
using namespace std;

ListNode *reverseLL(ListNode *temp, ListNode *end)
{
    ListNode *prev = NULL;
    while (temp != end)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k == 1)
        return head;

    ListNode *temp = head;
    ListNode *tail = head;

    for (int i = 0; i < k; i++)
    {
        if (!tail)
            return head;
        tail = tail->next;
    }
    ListNode *newHead = reverseLL(head, tail);
    head->next = reverseKGroup(tail, k);
    return newHead;
}

/*
🔹 Helper Function: reverseLL(temp, end)
Reverses a segment of the linked list starting from temp up to but not including end.
Standard iterative reversal:
    prev = NULL
    Traverse from temp to end, reversing next pointers.
Returns the new head of this segment after reversal.

🔹 Main Function: reverseKGroup(head, k)
1.Base cases
    Empty list (head == NULL) or only one node (head->next == NULL) → nothing to reverse.
    k == 1 → no reversal needed.

2.Check if there are at least k nodes
    Use tail pointer to move k steps forward.
    If less than k nodes remain → return head (leave as-is).

3.Reverse first k nodes
    Call reverseLL(head, tail) → returns newHead of this segment.

4.Recursively reverse remaining nodes
    head->next = reverseKGroup(tail, k)
        head is now the tail of the reversed segment → connect it to the next reversed group.

5.Return newHead
    This becomes the head of the fully processed list.
*/