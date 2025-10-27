#include <bits/stdc++.h>
using namespace std;

//M-1
int calcOnes(string temp)
{
    int totalOnes = 0;
    
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '1')
        totalOnes += 1;
    }
    return totalOnes;
}

int numberOfBeams(vector<string> &bank)
{
    int n = bank.size();
    int totalBeams = 0;
    int prev = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (calcOnes(bank[i]) > 0)
        {
            totalBeams += calcOnes(bank[i]) * prev;
            prev = calcOnes(bank[i]);
        }
    }
    return totalBeams;
}

//M-2
int calcOnes(string temp)
{
    int totalOnes = 0;

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '1')
            totalOnes += 1;
    }
    return totalOnes;
}

int numberOfBeams(vector<string> &bank)
{
    int n = bank.size();
    vector<int> storeOnes;

    for (int i = 0; i < n; i++)
    {
        if (calcOnes(bank[i]) != 0)
            storeOnes.push_back(calcOnes(bank[i]));
    }

    int totalBeams = 0;
    int m = storeOnes.size();

    for (int i = 0; i < m - 1; i++)
    {
        totalBeams = totalBeams + (storeOnes[i] * storeOnes[i + 1]);
    }
    return totalBeams;
}
