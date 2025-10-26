#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution 
{
public:

    int res = 0;

    int maxHt(TreeNode * root)
    {
        if(root == NULL)
            return 0;
        
        int leftH = maxHt(root->left);
        int rightH = maxHt(root->right);

        res = max(res,leftH + rightH);
        return max(leftH,rightH)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 0;

        maxHt(root);
        return res;
    }
};

// Max Ht of left part + Max Ht of right part.