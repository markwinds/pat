/*
报浮点错误，分母不能为0
to_string 将数字转换为string
atoi char to int
stoi string to int 
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    string a, b, c;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        b = a.substr(0, a.length() / 2);
        c = a.substr(a.length() / 2, a.length() / 2);
        if ((stoi(b) * stoi(c)) == 0)
            printf("No\n");
        else
            stoi(a) % (stoi(b) * stoi(c)) == 0 ? printf("Yes\n") : printf("No\n");
    }

    return 0;
}
