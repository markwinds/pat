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

int n, k;
bool visit[10010];
int fa[10010];

void init()
{
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < 10010; i++)
        fa[i] = i;
}

int findFa(int a)
{
    int b = a;
    while (fa[a] != a)
    {
        a = fa[a];
    }
    while (fa[b] != b)
    {
        int c = b;
        b = fa[b];
        fa[c] = a;
    }
    return a;
}

void Union(int a, int b)
{
    int f1 = findFa(a);
    int f2 = findFa(b);
    if (f1 != f2)
        fa[f1] = f2;
}

int main()
{
    init();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, sets;
        cin >> m;
        cin >> sets;
        visit[sets] = true;
        for (int i = 1; i < m; i++)
        {
            int temp;
            cin >> temp;
            visit[temp] = true;
            Union(sets, temp);
        }
    }
    int numb = 0;
    set<int> tree;
    for (int i = 0; i < 10010; i++)
    {
        if (visit[i] == true)
        {
            numb++;
            tree.insert(findFa(i));
        }
    }
    printf("%d %d\n", (int)tree.size(), numb);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int b1, b2;
        cin >> b1 >> b2;
        printf("%s\n", findFa(b1) == findFa(b2) ? "Yes" : "No");
    }
    return 0;
}