/*
if(-1) 的结果为true
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

struct Person
{
    int sets;
    int areas;
};

struct Fam
{
    int id;
    int num;
    int asets;
    int aareas;
    float avs;
    float ava;
} fam[10010];

int n;
int fa[10010];
int famNum = 0;
set<int> peo;
Person person[10010];
map<int, int> ptof;

void init()
{
    for (int i = 0; i < 10010; i++)
    {
        fa[i] = i;
    }
}

int findF(int a)
{
    int b = a;
    while (a != fa[a])
    {
        a = fa[a];
    }
    while (b != fa[b])
    {
        int c = b;
        b = fa[b];
        fa[c] = a;
    }
    return a;
}

void Union(int a, int b)
{
    int f1 = findF(a);
    int f2 = findF(b);
    if (f1 != f2)
        fa[f1] = f2;
}

bool cmp(Fam a, Fam b)
{
    return a.ava != b.ava ? a.ava > b.ava : a.id < b.id;
}

int main()
{
    cin >> n;
    init();
    for (int i = 0; i < n; i++)
    {
        int id, p1, p2, k, sets, areas;
        cin >> id >> p1 >> p2 >> k;
        peo.insert(id);
        if (p1 != -1)
        {
            Union(id, p1);
            peo.insert(p1);
        }
        if (p2 != -1)
        {
            Union(id, p2);
            peo.insert(p2);
        }
        for (int j = 0; j < k; j++)
        {
            int child;
            cin >> child;
            Union(id, child);
            peo.insert(child);
        }
        cin >> sets >> areas;
        person[id].areas = areas;
        person[id].sets = sets;
    }
    for (auto it = peo.begin(); it != peo.end(); it++)
    {
        int p = (*it);
        int f = findF(p);
        if (ptof.find(f) == ptof.end())
        {
            ptof[f] = famNum++;
            fam[famNum - 1].id = p;
        }
        int thisfam = ptof[f];
        fam[thisfam].num++;
        fam[thisfam].asets += person[p].sets;
        fam[thisfam].aareas += person[p].areas;
    }
    for (int i = 0; i < famNum; i++)
    {
        fam[i].ava = fam[i].aareas / (float)fam[i].num;
        fam[i].avs = fam[i].asets / (float)fam[i].num;
    }
    sort(fam, fam + famNum, cmp);
    cout << famNum << endl;
    for (int i = 0; i < famNum; i++)
    {
        printf("%04d %d %.3f %.3f\n", fam[i].id, fam[i].num, fam[i].avs, fam[i].ava);
    }
    return 0;
}