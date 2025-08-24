#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;

    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void print_DLL(Node * head)
{
    Node * node = head;
    if(head == NULL)
        return;
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

Node * convertArr2LL(vector<int>&arr)
{
    Node * head = new Node(arr[0]);
    Node * prev = head;

    for(int i=1 ;i<arr.size() ;i++)
    {
        Node * temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node * del_Head(Node * head)
{
    Node * temp = head;
    if(head == NULL || head->next == NULL)
        return NULL;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}

Node * del_Tail(Node * head)
{
    Node * temp = head;
    if(head == NULL || head->next == NULL)
        return NULL;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    Node * prevvi = temp->prev;
    prevvi->next = NULL;
    temp->prev = NULL;
    return head;
}

Node * del_at_Kth_pos(Node * head,int K)
{
    if(head == NULL)
        return NULL;
    if(K == 1)
    {
        Node * temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return head;
    }
    
    Node * res = head;
    Node * temp = NULL;
    int cnt = 0;

    while(res != NULL)
    {
        cnt++;
        if(cnt == K)
            break;
        res = res->next;
    }
    Node * back = res->prev;
    Node * front = res->next;

    if(back == NULL && front == NULL)
        return NULL;
    else if(back == NULL)
        return del_Head(head);
    else if(front == NULL)
        return del_Tail(front);
    back->next = front;
    front->prev = back;
    res->next = NULL;
    res->prev = NULL;
    delete res;
    return head;
}

void del_node_of_DLL(Node * temp)
{
    Node * back = temp->prev;
    Node * front = temp->next;

    if(front == NULL)
    {
        back->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }
    back->next = front;
    front->prev = back;

    temp->next = temp->prev = NULL;
    delete temp;
}

Node * insert_before_head(Node * head,int val)
{
    Node * temp = head;
    Node * newNode = new Node(val);
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    return newNode;
}

Node * insert_at_tail(Node * head,int val)
{
    Node * temp = head;
    Node * newNode = new Node(val);

    if(head == NULL)
        return newNode;
    
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

int main()
{
    Node * head = new Node(10);
    
    head->next = new Node(20);
    head->next->prev = head;

    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    print_DLL(head);
    cout<<endl;

    // head = del_Head(head);
    // print_DLL(head);
    // cout<<endl;

    // head = del_Tail(head);
    // print_DLL(head);
    // cout<<endl;

    // head = del_at_Kth_pos(head,3);
    // print_DLL(head);
    // cout<<endl;

    // del_node_of_DLL(head->next);
    // print_DLL(head);
    // cout<<endl;

    // head = insert_before_head(head,99);
    // print_DLL(head);
    // cout<<endl;

    head = insert_at_tail(head,101);
    print_DLL(head);
    cout<<endl;
}
