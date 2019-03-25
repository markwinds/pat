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

struct Person
{
    string name;
    int height;
};

int m, k;
Person input[10010];
vector<Person> per[13];

bool cmp(Person a, Person b)
{
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}

void outputs(vector<Person> a)
{
    int len = a.size();
    int temp = len - 1 - (len % 2);
    int i = temp;
    while (i != -1)
    {
        if (i != temp)
            printf(" ");
        cout << a[i].name;
        i -= 2;
    }
    temp = len - 1 - ((len + 1) % 2);
    i = 0;
    while (i != temp + 2)
    {
        printf(" ");
        cout << a[i].name;
        i += 2;
    }
    printf("\n");
}

int main()
{
    cin >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> input[i].name >> input[i].height;
    }
    sort(input, input + m, cmp);
    int ave = m / k;
    int loss = m % k;
    int num = 0;
    if (m == 1)
    {
        cout << input[0].name;
        return 0;
    }
    for (int i = 0; i < loss; i++)
    {
        per[0].push_back(input[num++]);
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < ave; j++)
        {
            per[i].push_back(input[num++]);
        }
    }
    for (int i = 0; i < k; i++)
    {
        outputs(per[i]);
    }
    return 0;
}