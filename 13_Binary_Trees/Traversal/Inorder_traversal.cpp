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

void inorder(Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main()
{
    Node *node = new Node(5);
    node->left = new Node(6);
    node->right = new Node(7);
    node->left->left = new Node(8);
    node->left->right = new Node(9);
    node->left->right->left = new Node(1);

    inorder(node);
}
