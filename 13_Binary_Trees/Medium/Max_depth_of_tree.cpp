#include <iostream>
#include <queue>
using namespace std;

//BFS Based
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    queue<TreeNode *> q;
    int depth = 0;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        depth++;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *t = q.front();
            q.pop();

            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    return depth;
}

//DFS Based
int func(TreeNode *root, int level)
{
    if (root == NULL)
        return level;

    int moveLeft = func(root->left, level + 1);
    int moveRight = func(root->right, level + 1);

    return max(moveLeft, moveRight);
}

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    return func(root, 0);
}