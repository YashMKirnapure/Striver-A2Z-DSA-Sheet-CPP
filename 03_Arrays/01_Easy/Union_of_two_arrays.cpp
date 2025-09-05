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

/*
Logic:

1. Use a hash set for uniqueness - Create an unordered_set which automatically handles duplicates (only stores unique values).
2. Add all elements from first array - Loop through arr1 and insert each element into the set:
Duplicates within arr1 are automatically ignored by the set
Each unique element is stored only once
3. Add all elements from second array - Loop through arr2 and insert each element into the set:
Duplicates within arr2 are automatically ignored
Elements that already exist from arr1 are also ignored (no duplicates across arrays)

4. Return the count - The size of the set represents the total number of unique elements across both arrays.

Example:
Input: arr1 = [1,2,3,2,1] and arr2 = [3,4,5,4,6]
After processing arr1: set contains {1,2,3}
After processing arr2: set contains {1,2,3,4,5,6}
Result: 6 (count of unique elements in the union)
*/