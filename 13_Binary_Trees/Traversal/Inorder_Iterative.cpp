#include <bits/stdc++.h>
using namespace std;

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;

    if (!root)
        return res;

    TreeNode *node = root;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            res.push_back(node->val);
            node = node->right;
        }
    }
    return res;
}