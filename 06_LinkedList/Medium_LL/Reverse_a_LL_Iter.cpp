#include <iostream>
using namespace std;

ListNode* reverseList(ListNode* head)
    {
        ListNode * curr = head;
        ListNode * prev = NULL;

        if(head == NULL || head->next == NULL)
            return head;

        while(curr!=NULL)
        {
            ListNode * front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }