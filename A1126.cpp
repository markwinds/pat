#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int n, m;
vector<int> adj[510];
int vnum[510];
bool visit[510];

void DFS(int index)
{
    visit[index] = true;
    int num = adj[index].size();
    for (int i = 0; i < num; i++)
    {
        int v = adj[index][i];
        if (visit[v] == false)
            DFS(v);
    }
}

bool checkMap()
{
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false)
            return false;
    }
    return true;
}

int main()
{
    memset(vnum, 0, sizeof(vnum));
    memset(visit, 0, sizeof(visit));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        vnum[v1]++;
        vnum[v2]++;
    }
    DFS(1);
    int num = 0;
    printf("%d", vnum[1]);
    if (vnum[1] % 2 == 1)
        num++;
    for (int i = 2; i <= n; i++)
    {
        printf(" %d", vnum[i]);
        if (vnum[i] % 2 == 1)
            num++;
    }
    if (num == 1 || num > 2 || !checkMap())
        printf("\nNon-Eulerian");
    else
        num == 0 ? printf("\nEulerian") : printf("\nSemi-Eulerian");
    return 0;
}
