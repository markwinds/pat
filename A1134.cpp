#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k;
bool visit[10009];
vector<int> adj[10009];

bool isT()
{
    for (int i = 0; i < m; i++)
    {
        if (visit[i] == false)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        adj[v1].push_back(i);
        adj[v2].push_back(i);
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int h;
        memset(visit, false, sizeof(visit));
        cin >> h;
        for (int j = 0; j < h; j++)
        {
            int temp;
            scanf("%d", &temp);
            for (int s = 0; s < adj[temp].size(); s++)
            {
                int v = adj[temp][s];
                visit[v] = true;
            }
        }
        isT() ? printf("Yes\n") : printf("No\n");
        // if (isT())
        // {
        //     printf("Yes\n");
        // }
        // else
        // {
        //     printf("No\n");
        // }
    }

    return 0;
}