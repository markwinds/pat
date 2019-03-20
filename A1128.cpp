#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool visit[2010];

int main()
{
    memset(visit, false, sizeof(visit));
    int k;
    int n;

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        int flag = 0;
        int old;
        memset(visit, false, sizeof(visit));
        for (int j = 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            if (j != 1)
            {
                if (temp = old + 1)
                    flag = 1;
            }
            temp += j;
            if (visit[temp] == true)
            {
                flag = 1;
            }
            visit[temp] = true;
            old = temp;
        }
        flag ? printf("No\n") : printf("Yes\n");
    }

    return 0;
}