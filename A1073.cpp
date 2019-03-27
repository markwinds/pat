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
    char c = getchar();
    if (c == '-')
        printf("-");
    cin >> a;
    int pe = 0;
    int len = a.size();
    pe = a.find('E');
    string b = a;
    int big = stoi(b.substr(pe + 1, len - pe - 1));
    b = b.substr(0, pe);
    int temp = b.find('.');
    b.erase(temp, 1);
    if (big < 0)
    {
        cout << "0.";
        while (big < -1)
        {
            cout << "0";
            big++;
        }
        cout << b;
        return 0;
    }
    else
    {
        for (int i = 0; i < b.size(); i++)
        {
            if (big == -1)
                cout << ".";
            cout << b[i];
            big--;
        }
        while (big > -1)
        {
            cout << "0";
            big--;
        }
    }

    return 0;
}
