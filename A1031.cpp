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
    string a;
    cin >> a;
    int len = a.size();
    int k = (len + 2) / 3;
    k--;
    int s = len - k * 2 - 2;
    string temp;
    while (s--)
        temp += " ";
    for (int i = 0; i < k; i++)
        cout << a[i] << temp << a[len - 1 - i] << endl;
    cout << a.substr(k, len - k * 2);
    return 0;
}