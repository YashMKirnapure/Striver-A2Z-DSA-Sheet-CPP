#include <iostream>
using namespace std;

ListNode * func(ListNode * prev,ListNode * curr)
    {
        if(curr == NULL)
            return prev;
        ListNode * front = curr->next;
        curr->next = prev;
        return func(curr,front);
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode * curr = head;
        ListNode * prev = NULL;

        if(head == NULL || head->next == NULL)
            return head;

        prev = func(prev,curr);
        return prev;
    }