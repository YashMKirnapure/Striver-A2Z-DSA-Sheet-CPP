#include <bits/stdc++.h>
using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *t1 = l1;
    ListNode *t2 = l2;
    ListNode *dummy = new ListNode(-1);
    ListNode *HeadD = dummy;

    int carry = 0;

    while (t1 != NULL || t2 != NULL || carry)
    {
        int sum = carry;

        if (t1 != NULL)
        {
            sum = sum + t1->val;
            t1 = t1->next;
        }
        if (t2 != NULL)
        {
            sum = sum + t2->val;
            t2 = t2->next;
        }
        carry = sum / 10;
        dummy->next = new ListNode(sum % 10);
        dummy = dummy->next;
    }
    return HeadD->next;
}