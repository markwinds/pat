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
    cout << "#";
    string a = "0123456789ABC";
    for (int i = 0; i < 3; i++)
    {
        int temp;
        cin >> temp;
        cout << a[temp / 13] << a[temp % 13];
    }
    return 0;
}