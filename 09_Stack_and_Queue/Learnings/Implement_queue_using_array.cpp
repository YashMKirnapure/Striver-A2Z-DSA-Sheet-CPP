#include <iostream>
using namespace std;

class Queue
{
    private:
    int *arr;
    int front;
    int rear;
    int size = 0;
    int cap;

    public:
    Queue(int c)
    {
        cap = c;
        arr = new int[cap];
        front = 0;
        rear = 0;
    }

    void enqueue(int x)
    {
        if (isFull())
            return;
        // int rear = getRear();
        int rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        front = (front + 1) % cap;
        size--;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    bool isFull()
    {
        return (size == cap);
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return arr[rear];
    }
};

int main()
{
    return 0;
}

/*
1. Initialization
    cap = maximum capacity.
    arr = array of size cap.
    front = 0, rear = 0, size = 0.

2. Enqueue (Insert element)
    If queue is full (size == cap) → can’t insert.
    Else:
        Find rear index → (getRear() + 1) % cap.
        Place element at arr[rear].
        Increase size.

3. Dequeue (Remove element)
    If queue is empty (size == 0) → nothing to remove.
    Else:
        Move front to next index → (front + 1) % cap.
        Decrease size.

4. isEmpty / isFull
    isEmpty: return true if size == 0.
    isFull: return true if size == cap.

5. Get Front
    If empty → return -1.
    else return arr[front]

6. Get Rear
    If empty → return -1.
    else return arr[rear]
*/