#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;

    maxheap.push(12);
    maxheap.push(3);
    maxheap.push(25);
    maxheap.push(44);
    maxheap.push(19);
    maxheap.push(20);

    cout<<"MAX HEAP"<<endl;
    while(!maxheap.empty())
    {
        cout<<maxheap.top()<<" ";
        maxheap.pop();
    }
    cout<<endl;
    cout<<maxheap.size();
    cout<<endl;
    cout<<"-------------------";
    cout<<endl;

    minheap.push(12);
    minheap.push(3);
    minheap.push(25);
    minheap.push(44);
    minheap.push(19);
    minheap.push(20);

    cout<<"MIN HEAP"<<endl;
    while(!minheap.empty())
    {
        cout<<minheap.top()<<" ";
        minheap.pop();
    }
    cout<<endl;
    cout<<minheap.size();
    cout<<endl;
}