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
int w[10010];
int dp[10010];
bool choose[10010][110];
// int len = 0;
vector<int> ans;

bool cmp(int a, int b) { return a > b; }

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    sort(w + 1, w + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            if (dp[j - w[i]] + w[i] >= dp[j])
            {
                choose[i][j] = true;
                dp[j] = dp[j - w[i]] + w[i];
            }
        }
    }
    if (dp[m] != m)
    {
        cout << "No Solution";
        return 0;
    }
    // int index = n + 1;
    // int weight = m;
    // while (--index)
    // {
    //     if (choose[index][weight])
    //     {
    //         ans.push_back(index);
    //         weight -= w[index];
    //     }
    // }

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     if (i != 0)
    //         cout << " ";
    //     cout << ans[i];
    // }
    vector<int> arr;
    int v = m, index = n;
    while (v > 0)
    {
        if (choose[index][v] == true)
        {
            arr.push_back(w[index]);
            v -= w[index];
        }
        index--;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", arr[i]);
    }
    // for (int i = arr.size() - 1; i >= 0; i--)
    // {
    //     if (i != arr.size() - 1)
    //         printf(" ");
    //     printf("%d", arr[i]);
    // }

    return 0;
}