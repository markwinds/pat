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
int datas[10010];
int dp[10010];
int mins[10010];
//int maxs[10010];
int flag = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> datas[i];
        if (datas[i] >= 0)
            flag = 1;
    }
    if (!flag)
    {
        printf("0 %d %d", datas[0], datas[n - 1]);
        return 0;
    }
    dp[0] = datas[0];
    mins[0] = 0;
    //maxs[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] >= 0)
        {
            dp[i] = dp[i - 1] + datas[i];
            mins[i] = mins[i - 1];
        }
        else
        {
            dp[i] = datas[i];
            mins[i] = i;
        }
    }
    int maxs = -10000000;
    int ans;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > maxs)
        {
            maxs = dp[i];
            ans = i;
        }
    }
    cout << dp[ans] << " " << datas[mins[ans]] << " " << datas[ans];
    return 0;
}