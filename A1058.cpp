/*
 数字     x1  x2  x3  x4
 进制     a   b   c   d
sum=x4+x3*d+x2*c*d+x1*b*c*d
转化为各位的数字
个位   sum%d
十位   sum/d%c
百位   sum/c/d%b
千位   sum/a
*/

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

// struct Num
// {
//     int a;
//     int b;
//     int c;
// };

// Num s1, s2, ans;

// int main()
// {
//     scanf("%d.%d.%d %d.%d.%d", &s1.a, &s1.b, &s1.c, &s2.a, &s2.b, &s2.c);
//     int temp = s1.c + s2.c;
//     int carry = temp / 29;
//     ans.c = temp % 29;
//     temp = s1.b + s2.b + carry;
//     carry = temp / 17;
//     ans.b = temp % 17;
//     temp = s1.a + s2.a + carry;
//     ans.a = temp;
//     printf("%d.%d.%d", ans.a, ans.b, ans.c);

//     return 0;
// }

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
    long long a, b, c, d, e, f;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
    long sum = (a + d) * 17 * 29 + (b + e) * 29 + c + f;
    printf("%ld.%ld.%ld", sum / (29 * 17), sum % (29 * 17) / 29, sum % 29);
    return 0;
}