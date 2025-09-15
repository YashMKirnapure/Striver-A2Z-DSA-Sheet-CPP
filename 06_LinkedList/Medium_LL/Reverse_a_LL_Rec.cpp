#include <iostream>
using namespace std;

ListNode *func(ListNode *prev, ListNode *curr)
{
    if (curr == NULL)
        return prev;
    ListNode *front = curr->next;
    curr->next = prev;
    return func(curr, front);
}

ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;

    if (head == NULL || head->next == NULL)
        return head;

    prev = func(prev, curr);
    return prev;
}

/*
1.Recursive helper (func)

Base case:
    If curr == NULL, it means we’ve gone past the last node → return prev (the new head).

Recursive case:
    Save the next node: front = curr->next.
    Reverse the link: curr->next = prev.
    Recurse: move forward by calling func(curr, front).

2.Main function (reverseList)
    Handles edge cases: if list is empty or has one node → return head.
    Otherwise, start recursion with prev = NULL and curr = head.
    The final return from recursion (prev) is the new head of the reversed list.
*/