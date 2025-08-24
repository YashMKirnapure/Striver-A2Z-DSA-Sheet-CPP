#include <iostream>
#include <unordered_set>
using namespace std;

int doUnion(vector<int> arr1, vector<int> arr2)
{
    unordered_set<int> st;
    for (int i = 0; i < arr1.size(); i++)
        st.insert(arr1[i]);
    for (int i = 0; i < arr2.size(); i++)
        st.insert(arr2[i]);
    return st.size();
}