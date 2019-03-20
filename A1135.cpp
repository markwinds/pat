#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int k, n;
int pre[35], in[35];
int deep = 0;
int flag = 0;

struct Node
{
    int data;
    bool color;
    Node *lchild;
    Node *rchild;
};

bool color[35];

Node *newNode(int data)
{
    Node *root = new Node;
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

Node *creatT(int preL, int preR, int inL, int inR)
{
    if (preL > preR)
        return NULL;
    int data = pre[preL];
    Node *root = newNode(data);
    root->color = color[preL];
    int k;
    for (k = inL; k <= inR; k++)
    {
        int now = in[k];
        if (data == now)
            break;
    }
    int num = k - inL;
    root->lchild = creatT(preL + 1, preL + num, inL, inL + num - 1);
    root->rchild = creatT(preL + num + 1, preR, inL + num + 1, inR);
    return root;
}

void DFS(Node *root)
{
    if (root == NULL)
    {
        if (flag == 0)
        {
            flag = deep;
            return;
        }
        if (flag != deep)
        {
            flag = -1;
            return;
        }
        return;
    }
    if (root->color == false)
    {
        if (root->lchild != NULL)
        {
            if (root->lchild->color == false)
            {
                flag = -1;
                return;
            }
        }
        if (root->rchild != NULL)
        {
            if (root->rchild->color == false)
            {
                flag = -1;
                return;
            }
        }
    }
    else
        deep++;
    DFS(root->lchild);
    DFS(root->rchild);
    if (root->color)
        deep--;
}

int main()
{
    cin >> k;
    memset(color, false, sizeof(color));
    int temp;
    for (int i = 0; i < k; i++)
    {
        deep = 0;
        flag = 0;
        cin >> n;
        memset(color, false, sizeof(color));
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp > 0)
            {
                color[i] = true;
            }
            else
                temp = -temp;
            pre[i] = temp;
            in[i] = temp;
        }
        sort(in, in + n);
        Node *root = creatT(0, n - 1, 0, n - 1);
        if (root->color == false)
        {
            printf("No\n");
            continue;
        }
        DFS(root);
        if (flag < 0)
            printf("No\n");
        else
        {
            printf("Yes\n");
        }
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;
// vector<int> arr;
// struct node
// {
//     int val;
//     struct node *left, *right;
// };
// node *build(node *root, int v)
// {
//     if (root == NULL)
//     {
//         root = new node();
//         root->val = v;
//         root->left = root->right = NULL;
//     }
//     else if (abs(v) <= abs(root->val))
//         root->left = build(root->left, v);
//     else
//         root->right = build(root->right, v);
//     return root;
// }
// bool judge1(node *root)
// {
//     if (root == NULL)
//         return true;
//     if (root->val < 0)
//     {
//         if (root->left != NULL && root->left->val < 0)
//             return false;
//         if (root->right != NULL && root->right->val < 0)
//             return false;
//     }
//     return judge1(root->left) && judge1(root->right);
// }
// int getNum(node *root)
// {
//     if (root == NULL)
//         return 0;
//     int l = getNum(root->left);
//     int r = getNum(root->right);
//     return root->val > 0 ? max(l, r) + 1 : max(l, r);
// }
// bool judge2(node *root)
// {
//     if (root == NULL)
//         return true;
//     int l = getNum(root->left);
//     int r = getNum(root->right);
//     if (l != r)
//         return false;
//     return judge2(root->left) && judge2(root->right);
// }
// int main()
// {
//     int k, n;
//     scanf("%d", &k);
//     for (int i = 0; i < k; i++)
//     {
//         scanf("%d", &n);
//         arr.resize(n);
//         node *root = NULL;
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &arr[j]);
//             root = build(root, arr[j]);
//         }
//         if (arr[0] < 0 || judge1(root) == false || judge2(root) == false)
//             printf("No\n");
//         else
//             printf("Yes\n");
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <malloc.h>
// #include <math.h>
// #include <string.h>
// using namespace std;
// #define N 33
// typedef struct BTree
// {
//     struct BTree *leftBTree;
//     int value;
//     struct BTree *rightBTree;
// } BTree;
// BTree *buildBTree(int *pre, int start, int end) //start和end用来限制访问的范围
// {                                               //根据二叉搜索树的性质和红黑树前序遍历序列来还原红黑树
//     if (start == end)                           //起始位置和结束位置相同，那么代表空节点
//         return NULL;
//     int i;
//     for (i = start; i < end; i++) //找到比pre[start]的第一个位置后停止
//     {                             //根据二叉搜索树的性质，该位置右侧的数在右子树上
//         if (abs(pre[i]) > abs(pre[start]))
//             break;
//     }
//     BTree *root = (BTree *)malloc(sizeof(BTree)); //建立"根节点"
//     root->value = pre[start];
//     root->leftBTree = buildBTree(pre, start + 1, i); //递归建立左子树
//     root->rightBTree = buildBTree(pre, i, end);      //递归建立右子树
//     return root;
// }
// int postOrder(BTree *root) //后续遍历检查路径上是否由相同的黑色节点数量
// {
//     if (root != NULL)
//     {
//         int leftBlack = postOrder(root->leftBTree);   //leftBlack存左子树的黑色节点数量
//         int rightBlack = postOrder(root->rightBTree); //rightBlack存右子树的黑色节点数量
//         if (leftBlack < 0 || rightBlack < 0 || rightBlack != leftBlack)
//             return -1;            //黑色节点数不相等，或左子树、右子树已经存在不等的黑色节点数则返回一个负数
//         else if (root->value < 0) //本节点为红色，则不加上本节点
//             return leftBlack;
//         else                      //本节点为黑色
//             return leftBlack + 1; //加上本黑色节点
//     }
//     return 0;
// }
// int previousOrder(BTree *root) //前序遍历用以检查是否有连续的两个红色节点
// {
//     if (root)
//     {
//         if (root->value < 0) //本届点为红色节点
//         {
//             if (root->leftBTree) //左子树非空
//             {
//                 if (root->leftBTree->value < 0) //左节点为红色
//                     return 1;                   //则返回真值（1），代表有连续的红色节点
//             }
//             if (root->rightBTree) //右子树非空
//             {
//                 if (root->rightBTree->value < 0) //右节点为红色
//                     return 1;                    //则返回真值（1），代表有连续的红色节点
//             }
//         }
//         return previousOrder(root->leftBTree) || previousOrder(root->rightBTree); //递归进行检查
//     }
//     return 0; //空节点则返回假值，代表没有连续的两个红色节点
// }
// int main()
// {
//     int k, n, preOrder[N];
//     scanf("%d", &k); //输入循环的次数
//     for (int i = 0; i < k; i++)
//     {
//         scanf("%d", &n);        //输入节点的个数,n为一个正数
//         memset(preOrder, 0, n); //将preOrder数组的前n个元素全部置为0
//         for (int j = 0; j < n; j++)
//             scanf("%d", &preOrder[j]); //存储前序遍历的序列
//         if (preOrder[0] < 0)           //负号代表红色节点,根节点为红色，则不符合要求
//         {                              //保证根节点是黑色的
//             printf("No\n");
//             continue;
//         }
//         BTree *root = buildBTree(preOrder, 0, n); //还原（构建）红黑树
//         //用后续遍历来判断是否连续的两个节点为红色，路径上的黑色节点数量是否相同
//         //balance用来存储路径的黑色节点是否相同，非负数相同，负数（-1）代表数量不相同
//         //continous用来存储两个红色的节点是否连续，1代表连续，
//         int balance = postOrder(root);
//         int continous = previousOrder(root);
//         //如果路径上黑色节点数量不同或者存在连续的红色节点
//         if (balance < 0 || continous == 1)
//             printf("No\n");
//         else
//             printf("Yes\n");
//     }
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// struct node
// {
//     int data;
//     node *lchild, *rchild;
// };
// void insert(node *&root, int x)
// {
//     if (root == NULL)
//     {
//         root = new node;
//         root->data = x;
//         root->lchild = root->rchild = NULL;
//         return;
//     }
//     if (abs(x) <= abs(root->data))
//         insert(root->lchild, x);
//     else
//         insert(root->rchild, x);
// }
// bool judge1(node *root)
// {
//     if (root == NULL)
//         return true;
//     if (root->data < 0)
//     {
//         if (root->lchild && root->lchild->data < 0)
//             return false;
//         if (root->rchild && root->rchild->data < 0)
//             return false;
//     }
//     return judge1(root->lchild) && judge1(root->rchild);
// }
// int getheight(node *root)
// {
//     if (root == NULL)
//         return 0;
//     int l = getheight(root->lchild);
//     int r = getheight(root->rchild);
//     return root->data > 0 ? max(l, r) + 1 : max(l, r);
// }
// bool judge2(node *root)
// {
//     if (root == NULL)
//         return true;
//     int l = getheight(root->lchild);
//     int r = getheight(root->rchild);
//     if (l != r)
//         return false;
//     return judge2(root->lchild) && judge2(root->rchild);
// }
// int k, n;
// vector<int> a;
// int main()
// {
//     scanf("%d", &k);
//     while (k--)
//     {
//         node *root = NULL;
//         scanf("%d", &n);
//         a.resize(n);
//         bool f = true;
//         for (int i = 0; i < n; i++)
//         {
//             scanf("%d", &a[i]);
//             insert(root, a[i]);
//         }
//         if (a[0] < 0 || judge1(root) == false || judge2(root) == false)
//             printf("No\n");
//         else
//             printf("Yes\n");
//     }
//     return 0;
// }
