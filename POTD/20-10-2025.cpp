#include <iostream>
#include <vector>
using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int n = operations.size();
    int val = 0;

    for (int i = 0; i < n; i++)
    {
        if (operations[i] == "++X" || operations[i] == "X++")
            val++;
        else
            val--;
    }
    return val;
}
