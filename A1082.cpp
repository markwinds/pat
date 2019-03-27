/*
用中文读一个数字，发现有2个问题
1.可以将数字拆分为4个一组来读，这样就拆分了问题
2.中文4个一组来读的时候比较难解决的是零的读法
分析：
如果不考虑零的话，那么问题就很简单了，只要独出每一位数字之后在后面加上自己的单位，最后在整个4个数字读完之后加上类似亿万等单位就行了
接下来考虑有零的情况，要把0加上去就要想在什么时候要读0
1.夹在来个非零的数之间
2.4个数字不都为0但是首部有零
总结一下就是从4位数的地位开始向前遍历，当出现过非0数之后出现0就要读而且读过一次0之后要再次出现非0数才能再次读0

最后就是空格的问题了，可以将答案先输出在一个string里，最后去掉首位的空格输出；
*/
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

string number[] = {"ling ", "yi ", "er ", "san ", "si ", "wu ", "liu ", "qi ", "ba ", "jiu "};
string rankN[] = {"", "Wan ", "Yi "};
string dgree[] = {"", "Shi ", "Bai ", "Qian "};

void init()
{
    for (int i = 0; i < 10; i++)
        reverse(number[i].begin(), number[i].end());
    for (int i = 0; i < 3; i++)
        reverse(rankN[i].begin(), rankN[i].end());
    for (int i = 0; i < 4; i++)
        reverse(dgree[i].begin(), dgree[i].end());
}

int main()
{

    string a, ans = "";
    cin >> a;
    if (a[0] == '-')
    {
        printf("Fu ");
        a = a.substr(1, a.size() - 1);
    }
    if (a.size() == 1 && a[0] == '0')
    {
        cout << "ling";
        return 0;
    }

    init();
    int index = a.size() - 1;
    int ranks = 0;
    while (index >= 0)
    {
        ans += rankN[ranks++];
        int flag1 = 0;
        for (int i = 0; i < 4 && index >= 0; i++)
        {
            int num = a[index] - '0';
            if (num != 0)
            {
                flag1 = 1; //flag1为1时需要显示0
                ans += dgree[i];
                ans += number[num];
            }
            else if (flag1)
            {
                flag1 = 0;
                ans += number[0];
            }
            index--;
        }
    }
    reverse(ans.begin(), ans.end());
    while (ans[0] == ' ')
        ans = ans.substr(1, ans.size() - 1);
    while (ans[ans.size() - 1] == ' ')
        ans = ans.substr(0, ans.size() - 1);
    cout << ans;
    return 0;
}