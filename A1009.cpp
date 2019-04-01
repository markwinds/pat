/*
队列中为零的元素不记录
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <cmath>

using namespace std;
vector<int> keyss;
vector<float> vals;
map<int, float> mp;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int keys;
        float val;
        cin >> keys >> val;
        keyss.push_back(keys);
        vals.push_back(val);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int keys;
        float val;
        cin >> keys >> val;
        int len = keyss.size();
        float sum = 0;
        int tempKey;
        for (int j = 0; j < len; j++)
        {
            tempKey = keyss[j] + keys;
            sum = val * vals[j];
            if (mp.find(tempKey) == mp.end())
                mp[tempKey] = 0;
            mp[tempKey] += sum;
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == 0)
            mp.erase(it);
    }
    cout << mp.size();
    auto it = mp.end();
    it--;
    for (; it != mp.begin(); it--)
    {
        printf(" %d %.1f", it->first, it->second);
    }
    printf(" %d %.1f", it->first, it->second);
    return 0;
}