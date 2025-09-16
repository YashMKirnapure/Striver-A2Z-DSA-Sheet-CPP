#include <bits/stdc++.h>
using namespace std;

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

/*
1. If the list has 0 or 1 nodes → return directly.

2. Keep two pointers:
    odd → points to odd-positioned nodes.
    even → points to even-positioned nodes.
    Also save the start of the even list in evenHead (important for final concatenation).

3. Traverse while possible:
    Link odd->next to next odd node (odd->next->next).
    Link even->next to next even node (even->next->next).
    Move odd and even forward.

4. Finally, attach the even list (evenHead) to the end of the odd list.
*/