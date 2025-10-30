#include <bits/stdc++.h>
using namespace std;

vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;

    if (root == NULL)
        return res;

    queue<pair<TreeNode *, int>> q;
    map<int, int> mp;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int level = it.second;

        mp[level] = node->val;

        if (node->left != NULL)
            q.push({node->left, level + 1});
        if (node->right != NULL)
            q.push({node->right, level + 1});
    }
    for (auto it : mp)
        res.push_back(it.second);
    return res;
}