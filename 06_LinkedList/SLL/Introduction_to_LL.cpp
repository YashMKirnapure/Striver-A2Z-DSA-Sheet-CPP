#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void LL_Traversal(Node *head)
{
    Node * node = head;
    if (node == NULL)
        return;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int lengthOfLL(Node * head)
{
    int cnt = 0;
    Node * node = head;
    if (node == NULL)
        return 0;
    while (node != NULL)
    {
        node = node->next;
        cnt++;
    }
    return cnt;
}

Node * convertArr2LL(vector<int>&arr)
{
    Node * head = new Node(arr[0]);
    Node * mover = head;

    for(int i=1 ;i<arr.size() ;i++)
    {
        Node * temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

bool checkIfPresent(Node * head,int val)
{
    Node * node = head;
    while(node != NULL)
    {
        if(node->data == val)
            return true;
        node = node->next;
    }
    return false;
}

int main()
{
    Node *node = new Node(10);
    node->next = new Node(20);
    node->next->next = new Node(30);
    node->next->next->next = new Node(40);

    LL_Traversal(node);
    cout<<endl;    
    vector <int> arr = {2,5,6,7};
    Node * head = convertArr2LL(arr);
    LL_Traversal(head);
    cout<<endl;    
    cout<<lengthOfLL(head);
    cout<<endl;    
    cout<<checkIfPresent(head,9);
}
