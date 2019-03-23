#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
};

int n;
int in[40], post[40];
stack<Node *> s1, s2;

Node *creatNode(int v)
{
    Node *root = new Node;
    root->data = v;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

Node *creatTree(int inL, int inR, int postL, int postR)
{
    if (inL > inR)
    {
        return NULL;
    }
    int data = post[postR];
    Node *root = creatNode(data);
    int k;
    for (k = inL; k <= inR; k++)
    {
        if (in[k] == data)
            break;
    }
    int num = k - inL;
    root->lchild = creatTree(inL, inL + num - 1, postL, postL + num - 1);
    root->rchild = creatTree(inL + num + 1, inR, postL + num, postR - 1);
    return root;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    Node *root = creatTree(0, n - 1, 0, n - 1);
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            if (temp->data != root->data)
                printf(" ");
            printf("%d", temp->data);
            if (temp->rchild)
                s2.push(temp->rchild);
            if (temp->lchild)
                s2.push(temp->lchild);
        }
        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            if (temp->data != root->data)
                printf(" ");
            printf("%d", temp->data);
            if (temp->lchild)
                s1.push(temp->lchild);
            if (temp->rchild)
                s1.push(temp->rchild);
        }
    }

    return 0;
}
