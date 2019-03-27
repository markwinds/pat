/*
检查输入是否合法的经典啊
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

char a[50], b[50];

int main()
{
    int n;
    cin >> n;
    float temp;
    float sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a);
        sscanf(a, "%f", &temp);   //保证是一个数字
        sprintf(b, "%.2f", temp); //为了保证是小数点后两位
        int flag = 1;
        for (int j = 0; j < strlen(a); j++) //注意这里不能用strcmp替代，因为输出%.2f会在整形的输入后面加上.00导致判等失败
            if (a[j] != b[j])
                flag = 0;
        if (!flag || abs(temp) > 1000)
            printf("ERROR: %s is not a legal number\n", a);
        else
        {
            sum += temp;
            cnt++;
        }
    }
    if (!cnt)
        printf("The average of 0 numbers is Undefined\n");
    else if (cnt == 1)
        printf("The average of 1 number is %.2f", sum / cnt);
    else
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);

    return 0;
}