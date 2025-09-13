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
        int rear = getRear();
        rear = (rear + 1) % cap;
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
            return front;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return (front + size - 1) % cap;
    }
};

int main()
{
    return 0;
}