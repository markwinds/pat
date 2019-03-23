/*
结构体里面操作符的重载可以让set完成排序的功能
本题既要排序，还要在每次排序后通过关键字查找并修改参数，vector方便排序但是不好查找修改，set方便查找但是排序要重载操作符
bool operator<(const Node &a) const
{
    return cnt == a.cnt ? num < a.num : cnt > a.cnt; 以后cmp里面的函数可以这么写
}
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct Node
{
    int num;
    int cnt;
    bool operator<(const Node &a) const
    {
        return cnt == a.cnt ? num < a.num : cnt > a.cnt;
    }
};

set<Node> s;
int n, k, num = 0;
int visit[50010] = {0};

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (i != 0)
        {
            printf("%d:", temp);
            int num = 0;
            for (auto it = s.begin(); num < k && it != s.end(); it++)
            {
                printf(" %d", (*it).num);
                num++;
            }
            printf("\n");
        }
        Node v = {temp, visit[temp]};
        auto it = s.find(v);
        if (it != s.end())
            s.erase(it);
        visit[temp]++;
        v = {temp, visit[temp]};
        s.insert(v);
    }

    return 0;
}

// #include <cstdio>
// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <algorithm>
// #include <set>
// #include <map>

// using namespace std;

// struct Node
// {
//     int num;
//     int cnt;
//     bool operator==(const Node &a) const
//     {
//         return cnt == a.cnt && num == a.num;
//     }
// };
// bool cmp(Node a, Node b)
// {
//     return a.cnt == b.cnt ? a.num < b.num : a.cnt > b.cnt;
// }

// int n, k, num = 0;
// vector<Node> lis;
// int visit[50010] = {0};

// int main()
// {
//     cin >> n >> k;

//     for (int i = 0; i < n; i++)
//     {
//         int temp;
//         cin >> temp;
//         if (i != 0)
//         {
//             printf("%d:", temp);
//             for (int i = 0; i < lis.size(); i++)
//             {
//                 printf(" %d", lis[i].num);
//             }
//             printf("\n");
//         }
//         Node v = {temp, visit[temp]};
//         auto it = find(lis.begin(), lis.end(), v);
//         if (it != lis.end())
//             lis.erase(it);
//         visit[temp]++;
//         v = {temp, visit[temp]};
//         lis.push_back(v);
//         sort(lis.begin(), lis.end(), cmp);
//     }

//     return 0;
// }
