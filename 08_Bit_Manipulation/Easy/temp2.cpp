#include <iostream>
using namespace std;

//Swap two numbers using bit manipulation
void swapTwoNums(int a,int b)
{
    cout<<"a: "<<a<<" b: "<<b<<endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"a: "<<a<<" b: "<<b;
}

//Check if the ith bit is set or not
bool CheckiThBit(int n,int i)
{
    //Right Shift Method
    if((n>>i)&1 == 1)
        return true;
    else
        return false;

    //Left Shift Method
    if((1<<i)&n == 1)
        return true;
    else
        return false;
}

//Set the ith bit
int setIthBit(int n,int i)
{
    return n | (1<<i);
}

//Clear the ith bit
int ClearIthBit(int n,int i)
{
    return n & ~(1<<i);
}

//Toggle the ith bit
int toggleIthBit(int n,int i)
{
    return n ^ (1<<i);
}

//Remove the last set bit
int removeLastBit(int n)
{
    return n & (n-1);
}

//Check if the number is a power of 2
bool PowerOf2(int n)
{
    return n > 0 && (n & (n-1)) == 0;
}

//Count the number of set bits
int countSetBits(int n)
{
    int cnt = 0;
    while(n>0)
    {
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

int main()
{
    // swapTwoNums(5,6);
    // cout<<CheckiThBit(13,2);
    // cout<<setIthBit(9,2);
    // cout<<ClearIthBit(9,2);
    // cout<<toggleIthBit(8,1);
    // cout<<removeLastBit(7);
    // cout<<PowerOf2(128);
    // cout<<countSetBits(18);
}