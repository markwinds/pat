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

int n, m;
int sum[100010] = {0};
int sums = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        sums += temp;
        sum[i] = sums;
    }
    cin >> m;
    while (m--)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if (t1 > t2)
            swap(t1, t2);
        int temp = sum[t2 - 1] - sum[t1 - 1];
        cout << min(temp, sums - temp) << endl;
    }

    return 0;
}