#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int n;
int rope[10010];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> rope[i];
    }
    sort(rope, rope + n);
    float ans = rope[0];
    for (int i = 1; i < n; i++)
    {
        ans += rope[i];
        ans /= 2;
    }
    printf("%d", (int)ans);
    return 0;
}
