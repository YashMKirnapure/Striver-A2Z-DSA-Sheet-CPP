#include <iostream>
using namespace std;

int lengthOfLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return 0;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int cnt = 1;
            fast = fast->next;
            while (fast != slow)
            {
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
    }
    return 0;
}

/*
1.Use Floyd’s Cycle Detection (slow & fast pointers).

2.When slow == fast, a loop exists.

3.To count loop length:
    Keep one pointer fixed (slow).
    Move the other pointer (fast) step by step until it comes back to slow.
    Count the steps → that’s the loop length.
*/