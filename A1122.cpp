/*
vector<int> v(k); 用来初始化vector
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

using namespace std;

int n, m;
//vector<int> adj[210];
bool adj[210][210];
vector<int> datas;
bool visit[210];

int main()
{
    memset(adj, false, sizeof(adj));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1][v2] = true;
        adj[v2][v1] = true;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        datas.clear();
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < num; i++)
        {
            int temp;
            cin >> temp;
            datas.push_back(temp);
        }
        if (num == n + 1 && datas[0] == datas[datas.size() - 1])
        {
            int len = datas.size();
            int flag = 1;
            for (int i = 0; i < len - 1; i++)
            {
                int v1 = datas[i];
                int v2 = datas[i + 1];
                if (!adj[v1][v2] || visit[v1] == true)
                {
                    flag = 0;
                    break;
                }
                visit[v1] = true;
            }
            printf("%s\n", flag ? "YES" : "NO");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
