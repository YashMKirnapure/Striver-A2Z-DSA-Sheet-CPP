#include <bits/stdc++.h>
using namespace std;

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        Node *next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }
    return prev;
}

/*Edge cases :

    If the list is
    empty(head == NULL) or
    has only one node,
    just return head.

    Initialization :

    temp → current node,
    starting from head.

    prev → keeps track of the new previous node(initially NULL)
        .

    Iterate through the list :

    Save the next node : next = temp -> next.

                                Reverse the next pointer : temp->next = prev.
                                Reverse the prev pointer : temp->prev = next.
                                Move prev forward to temp.
                                Move temp forward to next.
                                When loop ends :

    prev points to the new head of the reversed DLL.
    Return prev.
*/