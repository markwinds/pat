#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int k, n, m;
set<int> adj[1009];    //用来存哪些人有联系
int times[1005][1005]; //电话时长
bool isT[1005];
vector<int> you;
set<int>::iterator it;
bool visit[1004];

void DFS(int index, int deep)
{
    if (visit[index] == false && isT[index] == true)
    {
        if (deep != 1)
            cout << " ";
        printf("%d", index);
        visit[index] = true;
    }
    for (it = adj[index].begin(); it != adj[index].end(); it++)
    {
        int v = (*it);
        if (visit[v] == false && isT[v] == true)
        {
            DFS(v, deep++);
        }
    }
}

int main()
{
    cin >> k >> n >> m;

    //cout << "hello" << endl;

    int caller, receiver, duration;
    memset(times, 0, sizeof(times));
    memset(isT, false, sizeof(isT));
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &caller, &receiver, &duration);
        times[caller][receiver] += duration;
        adj[caller].insert(receiver);
    }

    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() > k)
        {
            int renum = 0;
            int shotnum = 0;
            //for(int j=0;j<adj[i].size();j++)
            for (it = adj[i].begin(); it != adj[i].end(); it++)
            {
                int v = (*it);
                if (times[i][v] <= 5)
                {
                    shotnum++;
                    if (times[v][i] != 0)
                        renum++;
                }
            }
            if (shotnum > k && renum * 5 <= adj[i].size())
            {
                isT[i] = true;
                you.push_back(i);
            }
        }
    }

    if (you.size() == 0)
    {
        printf("None\n");
        return 0;
    }

    memset(visit, false, sizeof(visit));
    //printf("%d\n",you.size());
    for (int i = 0; i < you.size(); i++)
    {
        int now = you[i];
        // if (visit[now] == false && isT[now] == true)
        // {
        //     visit[now] = true;
        //     printf("%d", now);
        //     for (it = adj[now].begin(); it != adj[now].end(); it++)
        //     {
        //         int v = (*it);
        //         if (isT[v] == true && visit[v] == false && times[now][v] != 0 && times[v][now] != 0)
        //         {
        //             printf(" %d", v);
        //             visit[v] = true;
        //         }
        //     }
        //     printf("\n");
        // }
        if (visit[now] == false)
        {
            DFS(now, 1);
        }
    }

    return 0;
}
