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

int n, m;
int len = 0;
vector<int> mon;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp <= m)
            mon.push_back(temp);
    }
    sort(mon.begin(), mon.end());
    len = mon.size();
    vector<vector<int>> d(len, len);

    return 0;
}