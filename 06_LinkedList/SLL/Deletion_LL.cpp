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

Node * delete_Head(Node * head)
{
    Node * node = head;
    if(node == NULL || node->next == NULL)
        return NULL;
    head = head->next;
    delete node;
    return head;
}

Node * deleted_tail(Node * head)
{
    Node * node = head;
    if(node == NULL || node->next == NULL)
        return NULL;
    while(node->next->next != NULL)
        node = node->next;
    delete node->next;
    node->next = NULL;
    return head;
}

Node * delete_at_Kth_pos(Node * head,int K)
{
    if(head == NULL)
        return NULL;
    if(K == 1)
    {
        Node * temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node * node = head;
    Node * temp = NULL;
    int cnt = 0;

    while(node!=NULL)
    {
        cnt++;
        if(cnt == K)
        {
            temp->next = temp->next->next;
            delete node;
            break;
        }
        temp = node;
        node = node->next;
    }
    return head;
}

Node * delete_Ele(Node * head,int Ele)
{
    if(head == NULL)
        return NULL;
    if(head->data == Ele)
    {
        Node * temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node * node = head;
    Node * temp = NULL;
    
    while(node!=NULL)
    {
        if(node->data == Ele)
        {
            temp->next = temp->next->next;
            delete node;
            break;
        }
        temp = node;
        node = node->next;
    }
    return head;
}

int main()
{
    Node * head = new Node(120);
    head->next = new Node(43);
    head->next->next = new Node(11);
    head->next->next->next = new Node(34);
    // printLL(head);
    // cout<<endl;
    // head = delete_Head(head);
    // cout<<endl;
    // printLL(head);
    // head = deleted_tail(head);
    // cout<<endl;
    // printLL(head);
    // cout<<endl;
    head = delete_at_Kth_pos(head,2);
    printLL(head);
    cout<<endl;

}
