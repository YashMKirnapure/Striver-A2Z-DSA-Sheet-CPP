#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Bank
{
public:
    map<int, long long> mp;
    Bank(vector<long long> &balance)
    {
        int n = balance.size();

        for (int i = 0; i < n; i++)
            mp[i + 1] = balance[i];
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (!mp.count(account1) || !mp.count(account2))
            return false;
        if (mp[account1] >= money)
        {
            mp[account1] -= money;
            mp[account2] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money)
    {
        if (!mp.count(account))
            return false;
        mp[account] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (!mp.count(account))
            return false;
        if (mp[account] >= money)
        {
            mp[account] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */