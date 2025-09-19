#include <bits/stdc++.h>
using namespace std;

void deleteAllOccurOfX(struct Node **head, int x)
{
    Node *temp = *head;

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            Node *toDel = temp;
            if (temp->prev == NULL)
            {
                *head = temp->next;
                if (*head)
                    (*head)->prev = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
            }
            temp = temp->next;
            delete toDel;
        }
        else
            temp = temp->next;
    }
}

/*
1.Traverse from head
    Start from temp = *head and go through every node.
2.Check if current node matches x
    If temp->data == x, we need to delete this node.
3.Handle deletion carefully
    There are 2 cases:
    Case 1: Deleting head node (prev == NULL)
        Move head to temp->next.
        If new head exists, set its prev = NULL.
    Case 2: Deleting non-head node
        Link temp->prev->next to temp->next.
        If temp->next exists, update its prev to temp->prev.
4.Delete node & move ahead
    Save node to toDel, move temp = temp->next, then delete toDel.
5.Else
    If no match, just move temp = temp->next.
*/