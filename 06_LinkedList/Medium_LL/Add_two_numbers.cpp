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

/*
🔹 Step-by-Step Logic

1. Dummy Node Setup
    Create a dummy node (HeadD) to simplify result list construction.
    dummy will be used as a moving pointer, while HeadD will always point to the start.

2. Traverse Lists with Carry
    While either t1, t2 exists, or carry is non-zero:
        Start with sum = carry.
        If t1 exists → add its digit to sum and move t1 forward.
        If t2 exists → add its digit to sum and move t2 forward.
        Update carry = sum / 10.
        Store sum % 10 as a new node in the result list.

3. Final Result
    If carry remains after traversal, it automatically gets handled because of the || carry condition in the while loop.
    Return HeadD->next (skip dummy).

🔹 Example Walkthrough

Input:
l1 = 2 → 4 → 3 (342)
l2 = 5 → 6 → 4 (465)

Steps:
    Iteration 1: 2 + 5 = 7 → carry 0 → result 7
    Iteration 2: 4 + 6 = 10 → store 0, carry 1 → result 7 → 0
    Iteration 3: 3 + 4 + carry(1) = 8 → store 8 → result 7 → 0 → 8

Output: 807
*/