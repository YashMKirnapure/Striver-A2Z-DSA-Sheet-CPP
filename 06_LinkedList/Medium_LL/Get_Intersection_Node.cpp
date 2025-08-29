#include <bits/stdc++.h>
using namespace std;

// ----Method 1----
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
if(headA == NULL || headB == NULL)
return NULL;

ListNode * h1 = headA;
ListNode * h2 = headB;

while(h1!=h2)
{
h1 = h1 ? h1->next : headB;
h2 = h2 ? h2->next : headA;
}
return h1;
}

// ----Method 2----
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
unordered_set <ListNode *> seen;

while(headA != NULL)
{
seen.insert(headA);
headA = headA->next;
}

while(headB != NULL)
{
if(seen.find(headB)!=seen.end())
return headB;
headB = headB->next;
}
return NULL;
}