#include <bits/stdc++.h>
using namespace std;

Node *segregate(Node *head)
{
    // Dummy nodes
    Node *zeroD = new Node(-1);
    Node *oneD = new Node(-1);
    Node *twoD = new Node(-1);

    // Current tails
    Node *zero = zeroD;
    Node *one = oneD;
    Node *two = twoD;

    Node *temp = head;

    // Distribute nodes into three lists
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    // Now connect the three lists
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL; // end of list

    // Head of new list
    Node *newHead = zeroD->next;

    return newHead;
}

/*
1. Create 3 dummy nodes:
    zeroD, oneD, twoD → to build separate chains for 0s, 1s, and 2s.
    Maintain tail pointers: zero, one, two.

    2.Traverse the original list:
    If data == 0, attach node to zero list.
    If data == 1, attach node to one list.
    If data == 2, attach node to two list.
    Move the tail pointer accordingly.

3. Re-connect the lists:
    Join 0s list with 1s list (or directly to 2s if 1s are empty).
    Then join 1s list to 2s list.
    Mark two->next = NULL to terminate the final list.

4. Return the new head:
    This will be zeroD->next (skipping dummy node).
*/
