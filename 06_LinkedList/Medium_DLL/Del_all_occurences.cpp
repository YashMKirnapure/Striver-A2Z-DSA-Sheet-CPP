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