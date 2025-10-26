#include <iostream>
using namespace std;

int maxHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);

    if (abs(lh - rh) > 1)
        return -1;

    if (lh == -1 || rh == -1)
        return -1;

    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
        return true;

    int height = maxHeight(root);

    return height == -1 ? false : true;
}