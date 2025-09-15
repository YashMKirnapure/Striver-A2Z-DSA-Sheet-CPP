#include <iostream>
using namespace std;

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    if (head == NULL || head->next == NULL)
        return head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/*
1.Edge cases:
    If the list is empty (head == NULL) or has only one node (head->next == NULL), return head (it’s already the middle).

2.Two pointers:
    slow → moves one step at a time.
    fast → moves two steps at a time.

3.Traversal:
    Move both pointers while fast and fast->next exist.
    This way, by the time fast reaches the end, slow will be at the middle.

4.Return middle:
    When the loop ends, slow points to the middle node.
*/