// #include <cstdio>
// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <algorithm>
// #include <map>
// #include <stack>
// #include <set>
// #include <queue>
// #include <cmath>

// using namespace std;

// struct Stu
// {
//     string name;
//     string id;
//     int sco;
//     bool operator<(const Stu &a) const
//     {
//         return sco < a.sco;
//     }
// };

// vector<Stu> m, f;
// int n;
// int flag = 0;

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         Stu temp;
//         cin >> temp.name;
//         getchar();
//         char c = getchar();
//         getchar();
//         cin >> temp.id;
//         cin >> temp.sco;
//         c == 'M' ? m.push_back(temp) : f.push_back(temp);
//     }
//     sort(f.begin(), f.end());
//     if (f.size() == 0)
//     {
//         flag = 1;
//         cout << "Absent" << endl;
//     }
//     else
//         cout << f[f.size() - 1].name<<" " << f[f.size() - 1].id << endl;

//     if (m.size() == 0)
//     {
//         flag = 1;
//         cout << "Absent" << endl;
//     }
//     else
//         cout << m[0].name <<" "<< m[0].id << endl;

//     if (flag == 1)
//     {
//         printf("NA");
//         return 0;
//     }
//     cout << f[f.size() - 1].sco - m[0].sco;

//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    string female, male;
    int femalescore = -1, malescore = 101;
    for (int i = 0; i < n; i++)
    {
        string name, sex, num;
        int score;
        cin >> name >> sex >> num;
        scanf("%d", &score);
        if (sex == "F")
        {
            if (femalescore < score)
            {
                femalescore = score;
                female = name + " " + num;
            }
        }
        else if (malescore > score)
        {
            malescore = score;
            male = name + " " + num;
        }
    }
    if (femalescore != -1)
        cout << female << endl;
    else
        printf("Absent\n");
    if (malescore != 101)
        cout << male << endl;
    else
        printf("Absent\n");
    if (femalescore != -1 && malescore != 101)
        printf("%d", femalescore - malescore);
    else
        printf("NA");
    return 0;
}