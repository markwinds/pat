// #include <cstdio>
// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <algorithm>
// #include <map>
// #include <stack>
// #include <set>
// #include <queue>
// #include <cmath>

// using namespace std;

// int main()
// {
//     long long int a = 9223372036854775807;
//     cout << a + 1;
//     return 0;
// }

////9223372036854775807

#include <cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if (a > 0 && b > 0 && sum < 0)
        {
            printf("Case #%d: true\n", i + 1);
        }
        else if (a < 0 && b < 0 && sum >= 0)
        {
            printf("Case #%d: false\n", i + 1);
        }
        else if (sum > c)
        {
            printf("Case #%d: true\n", i + 1);
        }
        else
        {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}