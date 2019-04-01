/*
队列中为零的元素不记录
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
float sum[1010];
int num = 0;

int main()
{
    for (int i = 0; i < 2; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int key;
            float val;
            cin >> key >> val;
            sum[key] += val;
        }
    }
    for (int i = 1001; i >= 0; i--)
        if (sum[i] != 0)
            num++;
    cout << num;
    for (int i = 1001; i >= 0; i--)
        if (sum[i] != 0)
            printf(" %d %.1f", i, sum[i]);
    return 0;
}