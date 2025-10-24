#include <bits/stdc++.h>
using namespace std;

vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    vector<int> res;

    if (root == NULL)
        return res;

    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        res.push_back(curr->val);

        if (curr->right != NULL)
            st.push(curr->right);
        if (curr->left != NULL)
            st.push(curr->left);
    }
    return res;
}