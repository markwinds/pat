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
set<int> st;

int findIt(int a)
{
    int sum = 0;
    while (a != 0)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        st.insert(findIt(temp));
    }
    printf("%d\n", (int)st.size());

    for (auto it = st.begin(); it != st.end(); it++)
    {
        if (it != st.begin())
            printf(" ");
        printf("%d", (*it));
    }
    return 0;
}