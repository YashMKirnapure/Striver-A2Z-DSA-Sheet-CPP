#include <iostream>
using namespace std;

Node *merge(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            res->bottom = list1;
            res = list1;
            list1 = list1->bottom;
        }
        else
        {
            res->bottom = list2;
            res = list2;
            list2 = list2->bottom;
        }
        res->next = NULL;
    }
    if (list1 != NULL)
        res->bottom = list1;
    else
        res->bottom = list2;
    if (dummyNode->bottom != NULL)
        dummyNode->bottom->next = NULL;
    return dummyNode->bottom;
}

Node *flatten(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *mergedHead = flatten(head->next);
    head = merge(head, mergedHead);
    return head;
}

/*
🔹 Helper Function: merge(list1, list2)
Merges two sorted linked lists connected via bottom pointers.
Steps:
    Create a dummy node to simplify edge cases.
    Compare list1->data and list2->data.
    Append the smaller node to res and move that pointer ahead.
    Continue until one list is exhausted.
    Append the remaining nodes of the other list.
    Ensure next pointers are nullified to avoid cycles.

🔹 Main Function: flatten(head)
1.Base case:
    If list is empty or only one node → return head.
2.Recursive flattening:
    Recursively flatten the head->next list first → mergedHead = flatten(head->next).
3.Merge current node's bottom list with flattened next list:
    head = merge(head, mergedHead)
4.Return head of fully flattened list.
*/