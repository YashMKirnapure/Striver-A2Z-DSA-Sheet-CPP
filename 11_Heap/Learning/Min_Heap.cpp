#include <iostream>
using namespace std;

class MinHeap
{
    int *arr;
    int size;       // total elements in heap
    int total_size; // total size of array

public:
    MinHeap(int ts)
    {
        size = 0;
        total_size = ts;
        arr = new int[ts];
    }

    // Insert into the heap
    void insert(int value)
    {
        //if heap size is available or not
        if(size == total_size)
        {
            cout<<"Heap Overflow\n";
            return;
        }
        arr[size] = value;
        int index = size;
        size++;

        //Compare it with its parent
        while(index>0 && arr[index] < arr[(index-1)/2])
        {
            swap(arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
        }
        cout<<arr[index]<<" is inserted into the heap\n";
    }

    void heapify(int index)
    {
        int smallest = index;
        int left = 2*index+1;
        int right = 2*index+2;

        // Smallest will store the index of the element which is smaller between parent,left child and right child

        if(left < size && arr[left]<arr[smallest])
            smallest = left;
        if(right < size && arr[right]<arr[smallest])
            smallest = right;
        
        if(smallest!=index)
        {
            swap(arr[index],arr[smallest]);
            heapify(smallest);
        }
    }

    // Delete from heap
    void delet()
    {
        if(size == 0)
        {
            cout<<"Heap underflow\n";
            return;
        }
        cout<<arr[0]<<" deleted from the heap\n";
        swap(arr[0],arr[size-1]);
        size--;

        if(size == 0)
            return;

        heapify(0);
    }

    void getMin()
    {
        if(size == 0)
        {
            cout<<"Heap is empty\n";
            return;
        }
        cout<<arr[0];
    }

    void print()
    {
        for(int i=0 ;i<size ;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    MinHeap H1(6);
    H1.insert(4);
    H1.insert(21);
    H1.insert(3);
    H1.insert(18);
    H1.insert(90);
    H1.insert(28);
    cout<<endl;
    H1.print();
    H1.delet();
    // H1.insert(128);
    H1.print();
    H1.getMin();
}