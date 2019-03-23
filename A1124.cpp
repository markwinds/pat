#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <set>

using namespace std;

int m, n, s;
string name[1010];
vector<string> st;

int main()
{
    cin >> m >> n >> s;
    if (s > m)
    {
        printf("Keep going...");
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> name[i];
    }
    while (s <= m)
    {
        while (find(st.begin(), st.end(), name[s]) != st.end() && s <= m)
        {
            s++;
        }
        if (s <= m)
        {
            st.push_back(name[s]);
            s += n;
        }
    }
    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i] << endl;
    }

    return 0;
}
