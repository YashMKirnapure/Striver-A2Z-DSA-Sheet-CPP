#include <bits/stdc++.h>
using namespace std;

// Method 1
bool isPalindrome(ListNode *head)
{
    ListNode *temp1 = head;
    ListNode *temp2 = head;

    while (temp2->next != NULL)
    temp2 = temp2->next;
    
    while (temp1 != temp2)
    {
        if (temp1->val != temp2->val)
        return false;
        temp1 = temp1->next;
    }
    return true;
}

// Method 2
bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = NULL;

    while (slow != NULL)
    {
        ListNode *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    ListNode *first = head;
    ListNode *second = prev;

    while (second != NULL)
    {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }
    return true;
}