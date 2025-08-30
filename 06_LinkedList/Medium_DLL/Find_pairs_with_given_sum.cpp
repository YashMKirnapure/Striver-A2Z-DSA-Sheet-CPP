#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> res;

    if (head == NULL)
        return res;

    Node *left = head;
    Node *right = head;

    while (right->next != NULL)
        right = right->next;

    while (left != right && right->next != left)
    {
        int sum = left->data + right->data;
        if (sum == target)
        {
            res.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum > target)
            right = right->prev;
        else
            left = left->next;
    }
    return res;
}