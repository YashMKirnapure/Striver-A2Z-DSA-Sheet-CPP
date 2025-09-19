#include <bits/stdc++.h>
using namespace std;

Node *removeDuplicates(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head;
    Node *headN = head->next;

    while (headN != NULL)
    {
        if (temp->data != headN->data)
        {
            temp->next = headN;
            headN->prev = temp;
            temp = temp->next;
        }
        headN = headN->next;
    }
    if (temp->next != NULL)
        temp->next = NULL;
    return head;
}

/*
1. Base case
    If head == NULL or head->next == NULL, return head (0 or 1 node → no duplicates possible).

2. Two pointers
    temp → tracks the last unique node.
    headN → moves forward checking for duplicates.

3. Traverse the DLL
While headN != NULL:
    If temp->data != headN->data
        Connect temp->next = headN
        Connect headN->prev = temp
        Move temp = temp->next (shift unique tracker forward).
    If equal → skip the duplicate (just move headN forward).

4. Fix dangling pointer
    After traversal, if temp->next != NULL, cut it off (temp->next = NULL) to avoid pointing into old duplicate nodes.

5. Return updated head
*/

Node *removeDuplicates(struct Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head;
    Node *back = NULL;
    set<int> st;

    while (temp != NULL)
    {
        if (st.find(temp->data) != st.end())
        {
            Node *toDel = temp;
            if (back != NULL)
                back->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = back;
            temp = temp->next;
            delete toDel;
        }
        else
        {
            st.insert(temp->data);
            back = temp;
            temp = temp->next;
        }
    }
    return head;
}
