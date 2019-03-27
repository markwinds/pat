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
vector<string> ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name, password;
        cin >> name >> password;
        int len = password.size();
        int flag = 0;
        for (int i = 0; i < len; i++)
        {
            switch (password[i])
            {
            case '1':
                password[i] = '@';
                flag = 1;
                break;
            case '0':
                password[i] = '%';
                flag = 1;
                break;
            case 'l':
                password[i] = 'L';
                flag = 1;
                break;
            case 'O':
                password[i] = 'o';
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            string temp;
            temp = name + " " + password;
            ans.push_back(temp);
        }
    }
    int len = ans.size();
    if (len)
    {
        cout << len << endl;
        for (int i = 0; i < len; i++)
            cout << ans[i] << endl;
    }
    else
    {
        if (n == 1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n", n);
    }

    return 0;
}