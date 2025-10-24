#include <bits/stdc++.h>
using namespace std;

// Using 2 Stacks
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    TreeNode *curr = root;
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;

    if (root == NULL)
        return res;

    st1.push(curr);

    while (!st1.empty())
    {
        curr = st1.top();
        st2.push(st1.top());
        st1.pop();

        if (curr->left != NULL)
            st1.push(curr->left);
        if (curr->right != NULL)
            st1.push(curr->right);
    }

    while (!st2.empty())
    {
        res.push_back(st2.top()->val);
        st2.pop();
    }
    return res;
}

// Using 1 Stacks
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    TreeNode *curr = root;
    stack<TreeNode *> st;

    if (root == NULL)
        return res;

    while (!st.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;

            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                res.push_back(temp->val);

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();

                    res.push_back(temp->val);
                }
            }
            else
                curr = temp;
        }
    }
    return res;
}