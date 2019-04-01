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

// struct Car
// {
//     string id;
//     int timeIn;
//     int timeOut;
// };
// map<string, int> nametonum;
// int num = 0;
// Car car[100000];
// int n;

// int toSec(int a, int b, int c)
// {
//     return a * 3600 + b * 60 + c;
// }

// bool cmp1(Car a, Car b)
// {
//     return a.timeIn < b.timeIn;
// }

// bool cmp2(Car a, Car b)
// {
//     return a.timeOut > b.timeOut;
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         string id;
//         int a, b, c;
//         cin >> id;
//         scanf("%d:%d:%d", &a, &b, &c);
//         int timeIn = toSec(a, b, c);
//         scanf("%d:%d:%d", &a, &b, &c);
//         int timeOut = toSec(a, b, c);
//         if (nametonum.find(id) == nametonum.end())
//         {
//             car[num].id = id;
//             car[num].timeIn = timeIn;
//             car[num].timeOut = timeOut;
//             nametonum[id] = num++;
//         }
//         int index = nametonum[id];
//         car[index].timeIn = min(car[index].timeIn, timeIn);
//         car[index].timeOut = max(car[index].timeOut, timeOut);
//     }
//     sort(car, car + num, cmp1);
//     cout << car[0].id << " ";
//     sort(car, car + num, cmp2);
//     cout << car[0].id;
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

int n;

int toSec(int a, int b, int c)
{
    return a * 3600 + b * 60 + c;
}

int main()
{
    cin >> n;
    string lock, unlock;
    int mins = 10000000;
    int maxs = -1;
    for (int i = 0; i < n; i++)
    {
        string tempId;
        cin >> tempId;
        int a, b, c;
        scanf("%d:%d:%d", &a, &b, &c);
        int timeIn = toSec(a, b, c);
        scanf("%d:%d:%d", &a, &b, &c);
        int timeOut = toSec(a, b, c);
        if (timeIn < mins)
        {
            mins = timeIn;
            unlock = tempId;
        }
        if (timeOut > maxs)
        {
            maxs = timeOut;
            lock = tempId;
        }
    }
    cout << unlock << " " << lock;
    return 0;
}