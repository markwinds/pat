/*
注意输入为零时在输出Yes后还要输出0
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

int n, b;
vector<int> ans, outs;

int main()
{
    cin >> n >> b;
    while (n)
    {
        int temp = n % b;
        n /= b;
        ans.push_back(temp);
    }
    outs = ans;
    reverse(ans.begin(), ans.end());
    printf("%s\n", outs == ans ? "Yes" : "No");
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            printf(" ");
        cout << ans[i];
    }
    if (ans.size() == 0)
        printf("0");

    return 0;
}