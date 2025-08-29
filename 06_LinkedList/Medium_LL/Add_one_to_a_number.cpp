#include <bits/stdc++.h>
using namespace std;

int addHelper(Node *temp)
{
    if (temp == NULL)
        return 1;
    int carry = addHelper(temp->next);
    temp->data += carry;

    if (temp->data < 10)
        return 0;

    temp->data = 0;
    return 1;
}

Node *addOne(Node *head)
{
    int carry = addHelper(head);
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *addOne(Node *head)
{
    head = reverseLL(head);
    Node *temp = head;
    int carry = 1;

    while (temp != NULL)
    {
        temp->data = temp->data + carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        head = reverseLL(head);
        newNode->next = head;
        return newNode;
    }
    head = reverseLL(head);
    return head;
}