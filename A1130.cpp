#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct Node
{
    string s;
    int ranks;
};
struct Data
{
    string data;
    int lchild;
    int rchild;
};

int n;
Data datas[30];
int fa[30];
int root = 0;

string findT(int index)
{
    if (index == -1)
    {
        return "";
    }
    string ls, rs;
    ls = findT(datas[index].lchild);
    rs = findT(datas[index].rchild);
    //只有当节点是根节点或者是叶子节点的时候返回的表达式没有括号
    return (datas[index].lchild == -1 && datas[index].rchild == -1 || index == root) ? ls + datas[index].data + rs : "(" + ls + datas[index].data + rs + ")";
}

int main()
{
    cin >> n;

    for (int i = 0; i < 25; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        char ss[100];
        int lchild, rchild;
        scanf("%s %d %d", ss, &lchild, &rchild);
        datas[i] = {ss, lchild, rchild};
        fa[lchild] = i;
        fa[rchild] = i;
    }
    int temp = 1;
    while (fa[temp] != temp)
    {
        temp = fa[temp];
    }
    root = temp;
    cout << findT(temp) << endl;

    return 0;
}
