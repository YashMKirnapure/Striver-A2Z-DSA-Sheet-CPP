#include <iostream>
using namespace std;

void insertCopyInBetween(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *copyNode = new Node(temp->val);
        Node *nextElement = temp->next;
        copyNode->next = nextElement;
        temp->next = copyNode;
        temp = nextElement;
    }
}

void connectRandomPointers(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *copyNode = temp->next;
        if (temp->random)
            copyNode->random = temp->random->next;
        else
            copyNode->random = NULL;
        temp = temp->next->next;
    }
}

Node *getDeepCopyList(Node *head)
{
    Node *temp = head;
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    while (temp != NULL)
    {
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

Node *copyRandomList(Node *head)
{
    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}