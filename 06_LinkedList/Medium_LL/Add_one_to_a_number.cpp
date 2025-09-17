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

/*
🔹 Helper Function: reverseLL
    Standard linked list reversal.
    Why? Because addition is easier if we start from the least significant digit (the tail).
        Example: 1 -> 9 -> 9 (represents 199) → reverse → 9 -> 9 -> 1.

🔹 Main Function: addOne
1. Reverse the linked list → so addition starts from the last digit.
    Example: 199 → reverse → 991.
2. Initialize carry = 1 (because we’re adding 1).
3. Traverse the list:
    Add carry to temp->data.
    If temp->data < 10:
    → No overflow → set carry = 0 and stop.
    Else (overflow, e.g., 9+1=10):
    → set temp->data = 0, keep carry = 1, and move forward.
4. After traversal, if carry is still 1 (like when input is 999):
    Create a new node with value 1.
    Reverse the list back.
    Put this new node at the front.
5. Reverse the list again to restore original order.
*/