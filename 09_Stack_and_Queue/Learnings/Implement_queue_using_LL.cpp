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

class Queue
{   
    public:
    Node * front;
    Node * rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(int x)
    {
        Node * newEle = new Node(x);
        if(rear == NULL)
        {
            front=rear=newEle;
            return;
        }
        rear->next = newEle;
        rear = newEle;
    }

    void pop()
    {
        if(front==NULL)
        {
            return;
        }
        Node * temp = front;
        front = front->next;
        if(front==NULL)
            rear = NULL;
        delete temp;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    q.pop();
    q.push(50);
    cout<<"Queue Front: "<<q.front->data<<endl;
    cout<<"Queue Rear: "<<q.rear->data<<endl;
}

/*
1. Push(x) (Enqueue):
    Create a new node with value x.
    If the queue is empty (rear == NULL), set both front and rear to the new node.
    Otherwise, attach the new node to rear->next and update rear to the new node.

2. Pop() (Dequeue):
    If the queue is empty (front == NULL), do nothing.
    Otherwise, remove the node at front and move front to front->next.
    If after removal the queue becomes empty, also set rear = NULL.
*/