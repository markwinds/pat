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

string number[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

int main()
{
    int sum = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        sum += c - '0';
    }
    string temp = to_string(sum);
    int len = temp.size();
    for (int i = 0; i < len; i++)
    {
        if (i != 0)
            printf(" ");
        cout << number[temp[i] - '0'];
    }

    return 0;
}