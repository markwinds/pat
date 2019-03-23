/*
递归或者循环，边界特别处理一下。注意标志量的更新。
最好先在纸上列好
一个用来存储的稀疏矩阵可以用map来代替，用矩阵的下标来映射矩阵里面的值
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
vector<int> adj[10020];
map<int, int> mp;
vector<int> tempans, ans;

int n, k;
int starts = 0, endst = 0;
bool visit[10020];
int minStation = 10020, minTra = 10020;

int countTra(vector<int> a)
{
    int num = 0;
    int now;
    int pre = mp[a[0] * 10000 + a[1]];
    int s = a.size();
    for (int i = 1; i < s - 1; i++)
    {
        now = mp[a[i] * 10000 + a[i + 1]];
        if (pre != now)
        {
            num++;
            pre = now;
        }
    }
    return num;
}

void DFS(int index)
{
    if (index == endst)
    {
        tempans.push_back(endst);
        int station = tempans.size();
        int tra = countTra(tempans);
        if (station < minStation || (station == minStation && tra < minTra))
        {
            minStation = station;
            minTra = tra;
            ans = tempans;
        }
        tempans.pop_back();
        return;
    }
    int s = adj[index].size();
    tempans.push_back(index);
    visit[index] = true;
    for (int i = 0; i < s; i++)
    {
        int v = adj[index][i];
        if (visit[v] == false)
            DFS(v);
    }
    visit[index] = false;
    tempans.pop_back();
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int k;
        int pre, now;
        cin >> k >> pre;
        for (int j = 1; j < k; j++)
        {
            cin >> now;
            adj[pre].push_back(now);
            adj[now].push_back(pre);
            mp[pre * 10000 + now] = i;
            mp[now * 10000 + pre] = i;
            pre = now;
        }
    }

    cin >> k;
    while (k--)
    {
        tempans.clear();
        ans.clear();
        memset(visit, false, sizeof(visit));
        minStation = 10020;
        minTra = 10020;
        cin >> starts >> endst;
        DFS(starts);
        printf("%d\n", minStation - 1);
        int preT = 0, preS = 0;
        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (mp[ans[i] * 10000 + ans[i + 1]] != preT)
            {
                if (i != 0)
                {
                    printf("Take Line#%d from %04d to %04d.\n", preT, preS, ans[i]);
                }
                preT = mp[ans[i] * 10000 + ans[i + 1]];
                preS = ans[i];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preT, preS, endst);
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// vector<vector<int>> v(10000);
// int visit[10000], minCnt, minTransfer, start, end1;
// unordered_map<int, int> line;
// vector<int> path, tempPath;
// int transferCnt(vector<int> a)
// {
//     int cnt = -1, preLine = 0;
//     for (int i = 1; i < a.size(); i++)
//     {
//         if (line[a[i - 1] * 10000 + a[i]] != preLine)
//             cnt++;
//         preLine = line[a[i - 1] * 10000 + a[i]];
//     }
//     return cnt;
// }
// void dfs(int node, int cnt)
// {
//     if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer)))   //找到一条更优路径
//     {
//         minCnt = cnt;
//         minTransfer = transferCnt(tempPath);
//         path = tempPath;
//     }
//     if (node == end1)
//         return;
//     for (int i = 0; i < v[node].size(); i++)
//     {
//         if (visit[v[node][i]] == 0)
//         {
//             visit[v[node][i]] = 1;
//             tempPath.push_back(v[node][i]);
//             dfs(v[node][i], cnt + 1);
//             visit[v[node][i]] = 0;      //这里研究一下
//             tempPath.pop_back();
//         }
//     }
// }
// int main()
// {
//     int n, m, k, pre, temp;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d%d", &m, &pre);
//         for (int j = 1; j < m; j++)
//         {
//             scanf("%d", &temp);
//             v[pre].push_back(temp);
//             v[temp].push_back(pre);
//             line[pre * 10000 + temp] = line[temp * 10000 + pre] = i + 1;
//             pre = temp;
//         }
//     }
//     scanf("%d", &k);
//     for (int i = 0; i < k; i++)
//     {
//         scanf("%d%d", &start, &end1);
//         minCnt = 99999, minTransfer = 99999;
//         tempPath.clear();
//         tempPath.push_back(start);
//         visit[start] = 1;
//         dfs(start, 0);
//         visit[start] = 0;
//         printf("%d\n", minCnt);
//         int preLine = 0, preTransfer = start;
//         for (int j = 1; j < path.size(); j++)
//         {
//             if (line[path[j - 1] * 10000 + path[j]] != preLine)
//             {
//                 if (preLine != 0)
//                     printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j - 1]);
//                 preLine = line[path[j - 1] * 10000 + path[j]];
//                 preTransfer = path[j - 1];
//             }
//         }
//         printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
//     }
//     return 0;
// }