#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>>preInPostTraversal(Node * root)
{
    stack<pair<Node *,int>>st;
    vector<int>pre;
    vector<int>in;
    vector<int>post;
    vector<vector<int>>all;

    if(!root)
        return all;

    st.push({root,1});

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        //this is part of pre. increment 1 to 2. push the left side of the tree.
        if(it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            
            if(it.first->left != NULL)
              st.push({it.first->left,1});
        }

        //this is part of in. increment 2 to 3. push the right side of the tree.
        else if(it.second == 2)
        {
            in.push_back(it.first->data);
                it.second++;
                st.push(it);

                if(it.first->right != NULL)
                    st.push({it.first->right,1});
            }
            // don't push it back again
        else{
            post.push_back(it.first->data);
        }
    }
    all.push_back(pre);
    all.push_back(in);
    all.push_back(post);

    return all;
}