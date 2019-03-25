/*
所有测试点都是格式错误又查不出错误 末尾加一个回车
先序遍历和后续遍历之所以不能确定一棵树是因为当一个节点的一棵子树为空时不能确定是左子树还是右子树比如  
pre  1 2 3 4 5
post 3 4 5 2 1
对于1这个节点，只能知道他有一棵子树为空一棵子树以2作为节点，但是并不能退出哪边是空
     
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

int n;
int pre[40], post[40];
vector<int> ans;

int creatTree(int preL, int preR, int postL, int postR)
{
    if (preR < preL)
        return 1;
    if (pre[preL] == post[postR])
    {
        int num = 0;
        int flag1 = 1;
        for (int k = 0; k <= preR - preL; k++)
        {
            vector<int> temp;
            temp = ans;
            int numL, numR;
            numL = creatTree(preL + 1, preL + k, postL, postL + k - 1);
            ans.push_back(pre[preL]);
            numR = creatTree(preL + k + 1, preR, postL + k, postR - 1);
            num += numL * numR;
            if (!(num != 0 && flag1 == 1))
                ans = temp;
            if (num != 0)
                flag1 = 0;
        }
        return num;
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    int num = creatTree(0, n - 1, 0, n - 1);
    printf("%s\n", num == 1 ? "Yes" : "No");
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}

// #include<iostream>
// #include<vector>
// #define N 36
// using namespace std;
// int pre[N];
// int post[N];
// bool flag;
// vector<int> res;
// void fi(int l1,int r1,int l2,int r2)
// {
// 	if (l1==r1)
// 	{
// 		res.push_back(pre[l1]);
// 		return ;
// 	}
// 	int pos=0;
// 	for (int i=l1+1;i<=r1;i++)
// 	{
// 		if (pre[i]==post[r2-1])
// 		{
// 			pos=i;
// 			break;
// 		}
// 	}
// 	int lenl=pos-l1-1;
// 	int lenr=r1-pos+1;
// 	if (pos==l1+1)	flag=1;
// 	else fi(l1+1,l1+lenl,l2,l2+lenl-1);
// 	res.push_back(pre[l1]);
// 	fi(pos,r1,r2-lenr,r2-1);
// }
// int main()
// {
// 	int n;
// 	cin>>n;
// 	for (int i=0;i<n;i++)	cin>>pre[i];
// 	for (int i=0;i<n;i++)	cin>>post[i];
// 	flag=0;
// 	fi(0,n-1,0,n-1);
// 	if (flag==0)
// 		cout<<"Yes"<<endl;
// 	else
// 		cout<<"No"<<endl;
// 	for (int i=0;i<res.size();i++)
// 	{
// 		if (i!=0) cout<<" ";
// 		cout<<res[i];
// 	}
// 	cout<<endl;
// 	return 0;
// }