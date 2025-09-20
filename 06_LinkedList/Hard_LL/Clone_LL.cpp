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

/*
🔹 Step 1: insertCopyInBetween(head)
    Traverse the original list.
    For each node, create a copy node with the same value.
    Insert it right after the original node.
This sets up the structure to easily set random pointers without extra space.

🔹 Step 2: connectRandomPointers(head)
    Traverse the modified list.
    For each original node:
        copyNode = temp->next
        Set copyNode->random = temp->random->next (the copy of the random node)
This works because each original node’s copy is right next to it.

🔹 Step 3: getDeepCopyList(head)
    Extract the copy nodes to form the deep copy list.
    Restore the original list by skipping over the copy nodes:

🔹 Step 4: copyRandomList(head)
    Combine all three steps:
        Insert copies in between   
        Connect random pointers
        Separate original and copied list
*/