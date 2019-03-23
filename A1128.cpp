#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

map<int, int> a, b, c;

int main()
{
    int k;
    int n;

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        int flag = 0;
        a.clear();
        b.clear();
        c.clear();
        for (int j = 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            if (a.count(temp) || b.count(temp + j) || c.count(temp - j))
                flag = 1;
            a[temp] = 1;
            b[temp + j] = 1;
            c[temp - j] = 1;
        }
        flag ? printf("NO\n") : printf("YES\n");
    }

    return 0;
}