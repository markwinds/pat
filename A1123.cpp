/*
判断是不是完全二叉树：中序遍历如果出现空孩子又出现有孩子就不是完全二叉树
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
    int data;
    Node *lchild;
    Node *rchild;
    int heigh;
};

int getHeigh(Node *root)
{
    return root == NULL ? 0 : root->heigh;
}

void updataHeigh(Node *root)
{
    root->heigh = max(getHeigh(root->lchild), getHeigh(root->rchild)) + 1;
}

int getFac(Node *root)
{
    return getHeigh(root->lchild) - getHeigh(root->rchild);
}

Node *newNode(int data)
{
    Node *root = new Node;
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    root->heigh = 1;
    return root;
}

void R(Node *&root)
{
    Node *temp;
    temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updataHeigh(root);
    updataHeigh(temp);
    root = temp;
    //return root;
}

void L(Node *&root)
{
    Node *temp;
    temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updataHeigh(root);
    updataHeigh(temp);
    root = temp;
    //return root;
}

void insertTree(Node *&root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        //return root;
        return;
    }
    if (data < root->data)
    {
        insertTree(root->lchild, data);
        updataHeigh(root);
        if (getFac(root) == 2)
        {
            if (getFac(root->lchild) == 1)
                R(root);
            else
            {
                L(root->lchild);
                R(root);
            }
        }
    }
    else
    {
        insertTree(root->rchild, data);
        updataHeigh(root);
        if (getFac(root) == -2)
        {
            if (getFac(root->rchild) == -1)
                L(root);
            else
            {
                R(root->rchild);
                L(root);
            }
        }
    }
}

int n;
//int input[30];

int main()
{
    cin >> n;
    Node *root = NULL;
    int temp;
    for (int i = 0; i < n; i++)
    {
        //cin >> input[i];
        cin >> temp;
        insertTree(root, temp);
    }

    int flag = 1;
    int bs = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->data != root->data)
            printf(" ");
        printf("%d", temp->data);
        if (temp->lchild)
        {
            q.push(temp->lchild);
            if (bs)
                flag = 0;
        }
        else
            bs = 1;
        if (temp->rchild)
        {
            q.push(temp->rchild);
            if (bs)
                flag = 0;
        }

        else
            bs = 1;
    }
    printf("\n");
    !flag ? printf("NO") : printf("YES");
    return 0;
}
