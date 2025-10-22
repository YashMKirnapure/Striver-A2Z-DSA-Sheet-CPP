#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *node)
{
    if (node == NULL)
        return;
    cout <<node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    Node *node = new Node(5);
    node->left = new Node(6);
    node->right = new Node(7);
    node->left->left = new Node(8);
    node->left->right = new Node(9);
    node->left->right->left = new Node(1);

    preorder(node);
}
