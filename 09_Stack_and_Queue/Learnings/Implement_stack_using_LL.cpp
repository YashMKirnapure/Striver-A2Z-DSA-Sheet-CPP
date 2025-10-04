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

class Stack
{
    private:
    int size;
    Node * head;

    public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    void push(int x)
    {
        Node * newEle = new Node(x);
        newEle->next = head;
        head = newEle;
        size++;
    }

    int pop()
    {
        if(head == NULL)
        {
            cout<<"Size is empty...\n";
            return 0;
        }
        int popEle = head->data;
        Node * temp = head;
        head = head->next;
        delete(temp);
        size--;
        return popEle;
    }

    int peek()
    {
        if(head == NULL)
        {
            cout<<"Size is empty...\n";
            return 0;
        }
        return head->data;
    }

    int sze()
    {
        return size;
    }

    bool isEmpty()
    {
        return head==NULL;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(23);
    st.push(30);
    cout<<st.isEmpty()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.sze()<<endl;
}

/*
Logic :
1. Push(x):
    Create a new node with value x.
    Insert it at the head of the linked list (so it becomes the new "top" of the stack).
    Increase size.

2. Pop():
    If the stack is empty, return error/0.
    Otherwise, take the value at the head (the "top"), move head to head->next, delete the old node, and reduce size.

3. Peek():
    Just return the data at the head (the "top" element), without removing it.

4. Size():
    Return the size counter.

5. isEmpty():
    Check if head == NULL.
*/