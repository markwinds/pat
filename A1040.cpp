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

bool dp[1001][1001];
int ans = 1;

int main()
{
    string a;
    getline(cin, a);
    int len = a.size();
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = true;
    }
    for (int i = 0; i < len - 1; i++)
        if (a[i] == a[i + 1])
        {
            dp[i][i + 1] = true;
            ans = 2;
        }
    for (int i = 3; i <= len; i++)
        for (int j = 0; j + i - 1 < len; j++)
        {
            int v = j + i - 1;
            if (dp[j + 1][v - 1] == true && a[j] == a[v])
            {
                dp[j][v] = true;
                ans = i;
            }
        }
    cout << ans;

    return 0;
}