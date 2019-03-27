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

int matrix[1000][1000];
int input[10000];
int n;
int indexs = 0;

bool cmp(int a, int b)
{
    return a > b;
}

void fillIt(int x, int y, int n, int m)
{
    for (int i = y; i < y + n; i++)
        matrix[x][i] = input[indexs++];
    for (int i = x + 1; i < x + m; i++)
        matrix[i][y + n - 1] = input[indexs++];
    for (int i = y + n - 2; i >= y; i--)
        matrix[x + m - 1][i] = input[indexs++];
    for (int i = x + m - 2; i >= x + 1 && n != 1; i--)
        matrix[i][y] = input[indexs++];
}

void findXY(int num, int &t1, int &t2)
{
    int s = (int)sqrt((double)num);
    for (int i = s; i >= 1; i--)
    {
        if (num % i == 0)
        {
            t1 = i;
            t2 = num / t1;
            break;
        }
    }
}

int main()
{
    cin >> n;
    int temp;
    int t1, t2;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n, cmp);
    findXY(n, t1, t2);
    int k = (t1 + 1) / 2;
    int s1 = t1;
    int s2 = t2;
    for (int i = 0; i < k; i++)
    {
        fillIt(i, i, t1, t2);
        t1 -= 2;
        t2 -= 2;
    }
    for (int i = 0; i < s2; i++)
    {
        for (int j = 0; j < s1; j++)
        {
            if (j != 0)
                printf(" ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}