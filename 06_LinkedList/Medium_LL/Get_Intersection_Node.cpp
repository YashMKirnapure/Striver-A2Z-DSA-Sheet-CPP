#include <bits/stdc++.h>
using namespace std;

// ----Method 1----
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;

    ListNode *h1 = headA;
    ListNode *h2 = headB;

    while (h1 != h2)
    {
        h1 = h1 ? h1->next : headB;
        h2 = h2 ? h2->next : headA;
    }
    return h1;
}

/*
----Method 1 LOGIC----

1. You have two pointers:
    h1 starts at headA
    h2 starts at headB
2. Move both one step at a time.
3. When a pointer reaches the end (NULL):
    Redirect it to the head of the other list.
4. Why does this work?
    Both pointers travel exactly lenA + lenB steps.
    If there is an intersection, they’ll meet at that node.
    If not, both will reach NULL together, and loop exits.
*/

// ----Method 2----
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_set<ListNode *> seen;

    while (headA != NULL)
    {
        seen.insert(headA);
        headA = headA->next;
    }

    while (headB != NULL)
    {
        if (seen.find(headB) != seen.end())
            return headB;
        headB = headB->next;
    }
    return NULL;
}

/*
----Method 2 LOGIC----
1. Traverse list A, store every node address in a hash set.
2. Traverse list B:
    If a node is already in the set → that’s the intersection node.
    If not, keep going.
3. If traversal ends with no match → no intersection.
*/