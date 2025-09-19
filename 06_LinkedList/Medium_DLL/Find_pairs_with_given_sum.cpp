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

/*
1. Initialize two pointers
    left → points to the head (smallest element).
    right → move to the tail (largest element).

2. Run a loop until they meet
    Condition: while (left != right && right->next != left)
        Ensures we don’t cross pointers.

3. Calculate sum
    sum = left->data + right->data

4. Check cases
If sum == target
    Store {left->data, right->data}.
    Move left = left->next and right = right->prev.
If sum > target
    Too large → move right = right->prev.
If sum < target
    Too small → move left = left->next.

5. Return results
    All valid pairs are stored in res
*/