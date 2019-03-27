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

int n;
string ins[250];

int main()
{
    cin >> n;
    int mins = 100000;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, ins[i]);
        reverse(ins[i].begin(), ins[i].end());
        int len = ins[i].size();
        if (len < mins)
            mins = len;
    }
    int flag = 1;
    int s = -1;
    while (flag && s < mins)
    {
        s++;
        char c = ins[0][s];
        for (int i = 1; i < n; i++)
        {
            if (ins[i][s] != c)
            {
                flag = 0;
                break;
            }
        }
    }
    if (s == 0)
    {
        cout << "nai";
        return 0;
    }
    string ans = ins[0].substr(0, s);
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}