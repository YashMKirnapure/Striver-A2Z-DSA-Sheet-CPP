#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

string findLexSmallestString(string s, int a, int b)
{
    int n = s.size();
    queue<string> q;
    set<string> vis;
    string smallest = s;

    q.push(s);
    vis.insert(s);

    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        if (smallest > curr)
            smallest = curr;

        // Add "a"
        string temp = curr;
        for (int i = 1; i < curr.length(); i += 2)
        {
            temp[i] = ((temp[i] - '0' + a) % 10) + '0';
        }

        if (!vis.count(temp))
        {
            q.push(temp);
            vis.insert(temp);
        }

        // Rotate right by "b"
        reverse(curr.begin(), curr.end());
        reverse(curr.begin(), curr.begin() + b);
        reverse(curr.begin() + b, curr.end());

        if (!vis.count(curr))
        {
            q.push(curr);
            vis.insert(curr);
        }
    }
    return smallest;
}