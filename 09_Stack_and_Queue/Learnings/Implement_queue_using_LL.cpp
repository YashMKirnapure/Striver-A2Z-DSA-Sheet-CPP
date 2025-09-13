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