#include <iostream>
using namespace std;

class Stack
{
    private:
        int top;
        int cap;
        int *st;
    public:
        Stack(int c)
        {
            top = -1;
            cap = c;
            st = new int[cap];
        }
        bool push(int x)
        {
            if(top >= cap-1)
            {
                cout<<"Stack Overflow...\n";
                return false;
            }
            top++;
            st[top] = x;
            return true;
        }
        int pop()
        {
            if(top < 0)
            {
                cout<<"Stack Underflow...\n";
                return 0;
            }
            return st[top--];
        }
        int peek()
        {
            if(top < 0)
            {
                cout<<"Stack Underflow...\n";
                return 0;
            }        
            return st[top];
        }
        bool isEmpty()
        {
            return top < 0;
        }
        int size()
        {
            return top+1;
        }
};

int main()
{
    Stack st(5);
    st.push(3);
    st.push(5);
    st.push(8);
    cout<<st.pop()<<" popped from the stack\n";
    cout<<st.size();
    cout<<endl;
    st.push(11);

    while(!st.isEmpty())
    {
        cout<<st.peek()<<" ";
        st.pop();
    }
}

/*
🔹 Stack (Array Implementation) — Logic in Plain Words
1. Initialization
    Create a stack with a fixed capacity cap.
    Start with top = -1 (meaning the stack is empty).
    Allocate an array st of size cap to hold stack elements.

2. Push (Insert an element)
    If top is already at cap - 1, the stack is full → Overflow.
    Otherwise, increment top and place the new element at st[top].

3. Pop (Remove top element)
    If top < 0, stack is empty → Underflow.
    Otherwise, return the element at st[top] and decrement top.

4. Peek (View top element without removing)
    If stack is empty (top < 0) → Underflow.
    Otherwise, return st[top].

5. isEmpty
    Return true if top < 0, else false.

6. Size
    Current size = top + 1.
*/