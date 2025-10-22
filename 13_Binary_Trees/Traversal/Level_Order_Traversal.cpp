#include <iostream>
#include <queue>
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

void BFS(Node *node)
{
    if (node == NULL)
        return;

    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        Node *curr = q.front();
        cout << curr->data << " ";
        q.pop();

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> LOT;

    if (root == NULL)
        return LOT;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        vector<int> temp;

        for (int i = 0; i < sz; i++)
        {
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if (curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
        LOT.push_back(temp);
    }
    return LOT;
}

int main()
{
    Node *node = new Node(5);
    node->left = new Node(6);
    node->right = new Node(7);
    node->left->left = new Node(8);
    node->left->right = new Node(9);
    node->left->right->left = new Node(1);

    BFS(node);
}
