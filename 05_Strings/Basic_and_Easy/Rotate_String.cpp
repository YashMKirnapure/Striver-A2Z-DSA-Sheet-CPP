#include <iostream>
using namespace std;

bool rotateString(string s1, string s2)
{
    string s3 = s1 + s1;

    if (s1.size() != s2.size())
        return false;

    return s3.find(s2) != string::npos;
}