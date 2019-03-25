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

struct Node
{
    int len;
    int times;
    int next;
};

int n, m;
vector<Node> adj[510];
int sumT[510] = {0};
int sumL[510] = {0};
int sta[510];
bool visit[510];
int starts, aims;
int pre[510];
vector<int> ansL, ansT;

void DjstL(int starts)
{
    fill(sumL, sumL + 510, 10000000);
    fill(sumT, sumT + 510, 10000000);
    memset(visit, false, sizeof(visit));
    sumL[starts] = 0;
    sumT[starts] = 0;
    for (int i = 0; i < n; i++)
    {
        int minLen = 1000000;
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (visit[i] == false && sumL[i] < minLen)
            {
                minLen = sumL[i];
                u = i;
            }
        }
        if (u == -1)
            return;
        visit[u] = true;
        for (int i = 0; i < adj[u].size(); i++)
        {
            Node v = adj[u][i];
            int now = v.next;
            int len = v.len;
            int times = v.times;
            if (visit[now] == false)
            {
                if (sumL[u] + len < sumL[now])
                {
                    sumL[now] = sumL[u] + len;
                    sumT[now] = sumT[u] + times;
                    pre[now] = u;
                }
                if (sumL[u] + len == sumL[now] && sumT[now] > sumT[u] + times)
                {
                    sumT[now] = sumT[u] + times;
                    pre[now] = u;
                }
            }
        }
    }
}

void DjstT(int starts)
{
    fill(sumT, sumT + 510, 10000000);
    memset(visit, false, sizeof(visit));
    fill(sta, sta + 510, 10000000);
    sumL[starts] = 0;
    sumT[starts] = 0;
    sta[starts] = 0;
    for (int i = 0; i < n; i++)
    {
        int minT = 1000000;
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (visit[i] == false && sumT[i] < minT)
            {
                minT = sumT[i];
                u = i;
            }
        }
        if (u == -1)
            return;
        visit[u] = true;
        for (int i = 0; i < adj[u].size(); i++)
        {
            Node v = adj[u][i];
            int now = v.next;
            int len = v.len;
            int times = v.times;
            if (visit[now] == false)
            {
                if (sumT[u] + times < sumT[now])
                {
                    sumT[now] = sumT[u] + times;
                    sta[now] = 1 + sta[u];
                    pre[now] = u;
                }
                if (sumT[u] + times == sumT[now] && sta[now] > sta[u] + 1)
                {
                    sta[now] = sta[u] + 1;
                    pre[now] = u;
                }
            }
        }
    }
}

void outP(vector<int> a)
{
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (i != a.size() - 1)
        {
            printf(" -> ");
        }
        printf("%d", a[i]);
    }
}

void getAns(vector<int> &a)
{
    int temp = aims;
    while (temp != starts)
    {
        a.push_back(temp);
        temp = pre[temp];
    }
    a.push_back(starts);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, flag, len, times;
        cin >> v1 >> v2 >> flag >> len >> times;
        Node v = {len, times, v2};
        adj[v1].push_back(v);
        v.next = v1;
        if (!flag)
            adj[v2].push_back(v);
    }
    cin >> starts >> aims;
    DjstL(starts);
    getAns(ansL);
    DjstT(starts);
    getAns(ansT);
    if (ansT != ansL)
    {
        printf("Distance = %d: ", sumL[aims]);
        outP(ansL);
        printf("\n");
        printf("Time = %d: ", sumT[aims]);
        outP(ansT);
        printf("\n");
    }
    else
    {
        printf("Distance = %d; Time = %d: ", sumL[aims], sumT[aims]);
        outP(ansL);
        printf("\n");
    }

    return 0;
}