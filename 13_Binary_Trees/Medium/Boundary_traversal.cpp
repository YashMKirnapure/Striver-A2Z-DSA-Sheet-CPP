#include <bits/stdc++.h>
using namespace std;

bool isLeaf(Node *root)
{
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->left;

    while (curr != NULL)
    {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left != NULL)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addRightBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->right;
    vector<int> temp;

    while (curr != NULL)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right != NULL)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
        res.push_back(temp[i]);
}

void addLeaves(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}