#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
int post[40];
int in[40];
int fullFlag = 0;

struct Point
{
    int lchild, rchild;
    int parant;
    int deep;
    int data;
    Point()
    {
        lchild = -1;
        rchild = -1;
        parant = -1;
        deep = -1;
    }
};

struct Node
{
    Node *lchild;
    Node *rchild;
    int data;
    int parant;
    int deep;
};

Point point[1009];

Node *newNode(int data)
{
    Node *root = new Node;
    root->lchild = NULL;
    root->rchild = NULL;
    root->data = data;
    return root;
}

Node *creatT(int postL, int postR, int inL, int inR)
{
    if (postL > postR)
        return NULL;
    int data = post[postR];
    Node *root = newNode(data);
    int k;
    for (k = inL; k < inR; k++)
    {
        if (in[k] == data)
            break;
    }
    int num = k - inL;
    root->lchild = creatT(postL, postL + num - 1, inL, inL + num - 1);
    root->rchild = creatT(postL + num, postR - 1, inL + num + 1, inR);
    return root;
}

void DFS(Node *index, int deep)
{
    int flag = 0;
    if (index == NULL)
        return;
    index->deep = deep++;
    int data = index->data;
    point[data].deep = index->deep;
    point[data].data = data;
    if (index->lchild == NULL)
        flag++;
    else
    {
        point[index->lchild->data].parant = data;
        point[data].lchild = index->lchild->data;
        index->lchild->parant = index->data;
        DFS(index->lchild, index->deep);
    }
    if (index->rchild == NULL)
        flag++;
    else
    {
        point[index->rchild->data].parant = data;
        point[data].rchild = index->rchild->data;
        index->rchild->parant = index->data;
        DFS(index->rchild, index->deep);
    }
    if (flag == 1)
        fullFlag++;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }

    Node *root = creatT(0, n - 1, 0, n - 1);
    point[root->data].parant = root->data;
    DFS(root, 0);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        bool flag = false;
        if (temp.find("root") != temp.end())
        {
        }
    }

    return 0;
}
