/*
检查是否是完全二叉树的一个新想法
将二叉树想象成是一棵完全二叉树，则下标会有一定的规律，l=2*n，r=2*n+1
递归得到下标最大的那个节点，比较节点个数是否和下标相等，相等就是完全二叉树

string输入是碰到空格就结束输入
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

struct Node
{
    int l;
    int r;
};

int n;
Node node[30];
char c1[5], c2[5];
bool visit[30] = {false};
int changed = 0;
int flag = 1;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", c1, c2);
        string s1 = c1;
        string s2 = c2;
        if (s1 == "-")
            node[i].l = -1;
        else
        {
            int temp = stoi(s1);
            node[i].l = temp;
            visit[temp] = true;
        }

        if (s2 == "-")
            node[i].r = -1;
        else
        {
            int temp = stoi(s2);
            node[i].r = temp;
            visit[temp] = true;
        }
    }
    int root;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    int index;
    while (!q.empty())
    {
        index = q.front();
        q.pop();
        if (node[index].l != -1)
        {
            q.push(node[index].l);
            if (changed)
                flag = 0;
        }
        else
        {
            changed = 1;
        }
        if (node[index].r != -1)
        {
            q.push(node[index].r);
            if (changed)
                flag = 0;
        }
        else
        {
            changed = 1;
        }
    }
    if (flag)
    {
        printf("YES %d", index);
    }
    else
        printf("NO %d", root);
    return 0;
}

// #include <cstdio>
// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <algorithm>
// #include <map>
// #include <stack>
// #include <set>
// #include <queue>

// using namespace std;
// struct node
// {
//     int l, r;
// } a[100];
// int maxn = -1, ans;
// void dfs(int root, int index)
// {
//     if (index > maxn)
//     {
//         maxn = index;
//         ans = root;
//     }
//     if (a[root].l != -1)
//         dfs(a[root].l, index * 2);
//     if (a[root].r != -1)
//         dfs(a[root].r, index * 2 + 1);
// }
// int main()
// {
//     int n, root = 0, have[100] = {0};
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         string l, r;
//         cin >> l >> r;
//         if (l == "-")
//         {
//             a[i].l = -1;
//         }
//         else
//         {
//             a[i].l = stoi(l);
//             have[stoi(l)] = 1;
//         }
//         if (r == "-")
//         {
//             a[i].r = -1;
//         }
//         else
//         {
//             a[i].r = stoi(r);
//             have[stoi(r)] = 1;
//         }
//     }
//     while (have[root] != 0)
//         root++;
//     dfs(root, 1);
//     if (maxn == n)
//         cout << "YES " << ans;
//     else
//         cout << "NO " << root;
//     return 0;
// }