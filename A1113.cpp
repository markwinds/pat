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
int input[100010];

int main()
{
    cin >> n;
    int sum = 0;
    printf("%d ", n % 2);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n);
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        sum -= input[i];
    }
    for (int i = (n - 2) / 2 + 1; i < n; i++)
    {
        sum += input[i];
    }
    printf("%d", sum);
    return 0;
}