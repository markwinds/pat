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

int num1 = 0, num2 = 0;
int maxdeep = 0;

struct Node
{
    int data;
    int heigh;
    Node *lchild;
    Node *rchild;
};

Node *newNode(int data)
{
    Node *root = new Node;
    root->data = data;
    root->lchild = root->rchild = NULL;
    root->heigh = 0;
    return root;
}

void insertTree(Node *&root, int data, int deep)
{
    if (!root)
    {
        root = newNode(data);
        root->heigh = deep;
        if (deep > maxdeep)
            maxdeep = deep;
        return;
    }
    root->heigh = deep;
    if (deep > maxdeep)
        maxdeep = deep;
    if (data <= root->data)
        insertTree(root->lchild, data, deep + 1);
    else
        insertTree(root->rchild, data, deep + 1);
}

void DFS(Node *root)
{
    if (!root)
        return;
    if (root->heigh == maxdeep)
        num1++;
    if (root->heigh == maxdeep - 1)
        num2++;
    DFS(root->lchild);
    DFS(root->rchild);
}

int n;

int main()
{
    int temp;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        insertTree(root, temp, 1);
    }
    DFS(root);
    printf("%d + %d = %d", num1, num2, num1 + num2);
    return 0;
}