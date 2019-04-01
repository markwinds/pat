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
int cton[210];
vector<int> que;
int dp[21000];
int ans = -1;

int main()
{
    cin >> n >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cton[temp] = i + 1;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (cton[temp])
            que.push_back(cton[temp]);
    }
    int len = que.size();
    for (int i = 0; i < len; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (que[j] <= que[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}