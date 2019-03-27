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
string hard = "SHCDJ";
string card[55];
int pos[55];
int ans[55];

int main()
{
    for (int i = 0; i < 54; i++)
        card[i + 1] = hard[(i) / 13] + to_string(i % 13 + 1); //周期为几就对几就行取余
    int n;
    cin >> n;
    for (int i = 1; i <= 54; i++)
        cin >> pos[i];
    for (int i = 1; i <= 54; i++)
    {
        int temp = i;
        for (int j = 0; j < n; j++)
            temp = pos[temp];
        ans[temp] = i;
    }
    for (int i = 1; i <= 54; i++)
    {
        if (i != 1)
            cout << " ";
        cout << card[ans[i]];
    }

    return 0;
}