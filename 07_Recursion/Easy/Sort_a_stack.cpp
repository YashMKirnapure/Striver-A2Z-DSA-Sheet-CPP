#include <iostream>
#include <stack>
using namespace std;

// Insert element into sorted stack
void sortedInsert(stack<int> &st, int x) {
  
    // If stack is empty or
    // top element is smaller, push x
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    // Recursively insert x in sorted order
    sortedInsert(st, x);

    st.push(top);
}

// Sort the stack recursively
void sortStack(stack<int> &st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();
    
    // Recursively sort the remaining stack
    sortStack(st);

    sortedInsert(st, top);
}

/*
We use recursion to sort the stack without relying on extra data structures. The approach will be:
1. Remove the top element of the stack.
2. Recursively sort the remaining stack.
3. Insert the removed element back into the stack in its correct sorted position.

How Recursion Works
1. Remove the top element of the stack and hold it temporarily.
2. Recursively sort the remaining stack, which is now smaller (it has one fewer element).
3. Once the smaller stack is sorted, insert the held element back into its correct position:
    If the stack is empty or the top element is smaller than the held element, push it directly.
    Otherwise, remove the top element, recursively find the correct position for the held element, and then push back the removed element.
4. Repeat this process as recursion unwinds until all elements are sorted in ascending order, with the smallest at the bottom and the largest at the top.
*/