#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;       // total elements in heap
    int total_size; // total size of array

public:
    MaxHeap(int ts)
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
        while(index>0 && arr[index] > arr[(index-1)/2])
        {
            swap(arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
        }
        cout<<arr[index]<<" is inserted into the heap\n";
    }

    void heapify(int index)
    {
        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;

        // Largest will store the index of the element which is greater between parent,left child and right child

        if(left < size && arr[left]>arr[largest])
            largest = left;
        if(right < size && arr[right]>arr[largest])
            largest = right;
        
        if(largest!=index)
        {
            swap(arr[index],arr[largest]);
            heapify(largest);
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
    
    void getMax()
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
    MaxHeap H1(6);
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
    H1.getMax();
}