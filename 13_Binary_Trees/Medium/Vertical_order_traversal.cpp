#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool myCmp(pair<TreeNode *, pair<int, int>> &t1, pair<TreeNode *, pair<int, int>> &t2)
    {
        if (t1.second.second != t2.second.second)
            return t1.second.second < t2.second.second;
        if (t1.second.first != t2.second.first)
            return t1.second.first < t2.second.first;
        return t1.first->val < t2.first->val;
    }

    void preTrav(TreeNode *root, int left, int right, vector<pair<TreeNode *, pair<int, int>>> &temp)
    {
        if (root == NULL)
            return;
        temp.push_back({root, {left, right}});
        preTrav(root->left, left + 1, right - 1, temp);
        preTrav(root->right, left + 1, right + 1, temp);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;
        vector<pair<TreeNode *, pair<int, int>>> temp;
        if (root->left == NULL && root->right == NULL)
        {
            res.push_back({root->val});
            return res;
        }

        preTrav(root, 0, 0, temp);
        sort(temp.begin(), temp.end(), myCmp);
        int prevCol = INT_MIN;

        for (auto node : temp)
        {
            if (node.second.second != prevCol)
            {
                res.push_back({});
                prevCol = node.second.second;
            }
            res.back().push_back(node.first->val);
        }
        return res;
    }
};