/*
本题要注意不同地址里面的数据有可能是一样的
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

struct Node
{
    int addr;
    int data;
    int next;
};

Node node[100010];
vector<Node> ha, temp;
int k;

int ranks(int a)
{
    if (a < 0)
        return 3;
    if (a <= k)
        return 2;
    return 1;
}
bool cmp(Node a, Node b)
{
    if (ranks(a.data) != ranks(b.data))
        return ranks(a.data) > ranks(b.data);
    return false;
}

int main()
{
    int start, n;

    cin >> start >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int addr, data, next;
        cin >> addr >> data >> next;
        node[addr] = {addr, data, next}; //这里结构体的赋值可以学习一下
    }
    while (start != -1) //这里的停止条件可以学习一下
    {
        ha.push_back(node[start]);
        start = node[start].next;
    }

    sort(ha.begin(), ha.end(), cmp);
    /*把sort这行换成下面这段就可以，所以怀疑是不是sort的问题
    temp = ha;
    ha.clear();
    for (int i = 0; i < temp.size(); i++)
        if (temp[i].data < 0)
            ha.push_back(temp[i]);
    for (int i = 0; i < temp.size(); i++)
        if (temp[i].data >= 0 && temp[i].data <= k)
            ha.push_back(temp[i]);
    for (int i = 0; i < temp.size(); i++)
        if (temp[i].data > k)
            ha.push_back(temp[i]);
    sort(temp.begin(), temp.end(), cmp);
    */



    for (int i = 0; i < ha.size() - 1; i++)
    {
        Node v = ha[i];
        if (v.addr == ha[i + 1].addr && v.data == ha[i + 1].data)
            while (1)
                ;
        printf("%05d %d %05d\n", v.addr, v.data, ha[i + 1].addr);
    }
    Node v = ha[ha.size() - 1];
    printf("%05d %d -1\n", v.addr, v.data);
    return 0;
}