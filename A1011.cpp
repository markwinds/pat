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

int main()
{
    float a, b, c;
    float ans = 1;
    float maxs;
    int n = 3;
    while (n--)
    {
        if (n != 2)
            printf(" ");
        scanf("%f %f %f", &a, &b, &c);
        maxs = max(a, b);
        maxs = max(maxs, c);
        ans *= maxs;
        printf("%c", maxs == a ? 'W' : maxs == b ? 'T' : 'L');
    }
    printf(" %.2f", (ans * 0.65 - 1) * 2);
    return 0;
}