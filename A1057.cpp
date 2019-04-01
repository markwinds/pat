/*
数状数组用来查询一个经常有增删数列中第k个大的数
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
#include <cmath>

using namespace std;

int n;
stack<int> s;
// vector<int> tos;

int sum[100010]; //数状数组
int maxs = 100009;

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int v) //插入一个数字
{
    for (int i = x; i <= maxs; i += lowbit(i))
    {
        sum[i] += v;
    }
}

int getSum(int x) //计算有几个数字小于等于x
{
    int ans = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        ans += sum[i];
    return ans;
}

int peekM(int k)
{
    int l = 1, r = maxs + 1;
    int mid = (l + r) / 2;
    while (l != r)
    {
        mid = (l + r) / 2;
        if (getSum(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    cin >> n;
    getchar();
    string a, b;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        getline(cin, a);
        b = a.substr(0, 3);
        if (b == "Pus")
        {
            sscanf(a.c_str(), "Push %d", &temp);
            s.push(temp);
            update(temp, 1);
        }
        else if (b == "Pop")
        {
            if (s.empty())
                cout << "Invalid" << endl;
            else
            {
                int num = s.top();
                cout << num << endl;
                s.pop();
                update(num, -1);
            }
        }
        else
        {
            if (s.empty())
                cout << "Invalid" << endl;
            else
            {
                cout << peekM((s.size() + 1) / 2) << endl;
            }
        }
    }
    return 0;
}