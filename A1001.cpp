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
//     int a, b;
//     cin >> a >> b;
//     a += b;
//     if (a < 0)
//     {
//         printf("-");
//         a = -a;
//     }
//     string temp = to_string(a);
//     int len = temp.size();
//     int k = len % 3;
//     int index = 0;
//     int n = k;
//     while (k--)
//     {
//         cout << temp[index++];
//     }
//     int s = index;
//     while (index < len - 1)
//     {
//         if (!(n == 0 && index == s))
//             printf(",");
//         for (int i = 0; i < 3; i++)
//             cout << temp[index++];
//     }
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
    int a, b;
    cin >> a >> b;
    a += b;
    string temp = to_string(a);
    int len = temp.size();
    int k = len % 3;
    for (int i = 0; i < len; i++)
    {
        cout << temp[i];
        if (temp[i] == '-')
            continue;
        if (i == len - 1)
            break;
        if ((i + 4 - k) % 3 == 0)
            cout << ',';
    }
    return 0;
}