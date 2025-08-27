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