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