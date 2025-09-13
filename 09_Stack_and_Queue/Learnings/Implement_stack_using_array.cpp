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