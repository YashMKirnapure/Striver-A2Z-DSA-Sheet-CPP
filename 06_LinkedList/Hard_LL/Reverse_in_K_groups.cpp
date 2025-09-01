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