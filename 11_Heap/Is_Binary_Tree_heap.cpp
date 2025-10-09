#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


bool isHeap(Node *root)
{
    if (root == NULL)
        return true;

    queue<Node *> q;
    q.push(root);
    bool nullChildSeen = false;

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // Check for left child
        if (curr->left)
        {
            if (nullChildSeen || curr->data < curr->left->data)
                return false;
            q.push(curr->left);
        }
        else
            nullChildSeen = true;

        // Check for right child
        if (curr->right)
        {
            if (nullChildSeen || curr->data < curr->right->data)
                return false;
            q.push(curr->right);
        }
        else
            nullChildSeen = true;
    }
    return true;
}