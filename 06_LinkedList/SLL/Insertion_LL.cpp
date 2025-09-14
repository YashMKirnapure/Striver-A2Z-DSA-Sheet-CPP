#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void printLL(Node * head)
{
    Node * node = head;
    if(node == NULL)
        return;
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

Node * insert_at_head(Node * head,int ele)
{
    if(head == NULL)
    {
        Node * newNode = new Node(ele);
        return newNode;
    }
    Node * newNode = new Node(ele);
    newNode->next = head;
    head = newNode;
    return head;
}

Node * insert_at_tail(Node * head,int ele)
{
    if(head == NULL)
    {
        Node * newNode = new Node(ele);
        return newNode;
    }
    Node * node = head;
    while(node->next!=NULL)
        node = node->next;
    Node * newNode = new Node(ele);
    node->next = newNode;
    return head;
}

Node * insert_at_kth_pos(Node * head,int K,int ele)
{
    if(head == NULL)
    {
        if(K == 1)
        {
            Node * newNode = new Node(ele);
            return newNode;
        }
        return NULL;
    }
    
    if(K == 1)
    {
        return insert_at_head(head,ele);
    }
    
    Node * temp = head;
    int cnt = 0;

    while(temp!=NULL)
    {
        cnt++;
        if(cnt == K-1)
        {
            Node * newNode = new Node(ele);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node * insert_before_val(Node * head,int ele,int val)
{
    if(head == NULL)
        return NULL;
    
    if(head->data == val)
    {
        // Node * newNode = new Node(ele);
        // return newNode;
    }
        return NULL;
    
    if(head->data == val)
    {
        // return new Node(ele);
    }
    
    Node * temp = head;
    int cnt = 0;

    while(temp->next!=NULL)
    {
        if(temp->next->data == val)
        {
            Node * newNode = new Node(ele);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    Node * node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    
    node = insert_at_head(node,77);
    printLL(node);
    cout<<endl;

    node = insert_at_tail(node,88);
    printLL(node);
    cout<<endl;
}
