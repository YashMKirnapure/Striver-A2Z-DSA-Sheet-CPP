#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode *> q;

    if (root == NULL)
        return res;

    q.push(root);
    bool flag = true;

    while (!q.empty())
    {
        int sz = q.size();
        vector<int> temp(sz);

        for (int i = 0; i < sz; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            int idx = flag ? i : (sz - i - 1);
            temp[idx] = curr->val;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        res.push_back(temp);
        flag = !flag;
    }
    return res;
}

// vector<vector<int>> zigzagLevelOrder(TreeNode *root)
// {
//     vector<vector<int>> res;
//     queue<TreeNode *> q;

//     if (root == NULL)
//         return res;

//     q.push(root);

//     while (!q.empty())
//     {
//         vector<int> temp;
//         int sz = q.size();

//         for (int i = 0; i < sz; i++)
//         {
//             TreeNode *curr = q.front();
//             q.pop();
//             temp.push_back(curr->val);

//             if (curr->left)
//                 q.push(curr->left);
//             if (curr->right)
//                 q.push(curr->right);
//         }
//         res.push_back(temp);
//     }

//     for (int i = 0; i < res.size(); i++)
//     {
//         if (i % 2 == 1)
//             reverse(res[i].begin(), res[i].end());
//     }
//     return res;
// }