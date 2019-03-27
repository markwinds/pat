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

string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    string ins[4];
    cin >> ins[0] >> ins[1] >> ins[2] >> ins[3];
    int num = 2;
    int day, hour, sec;
    int temp = 0;
    while (ins[0][temp] != ins[1][temp] || !(ins[0][temp] >= 'A' && ins[0][temp] <= 'G')) //day A-G
        temp++;
    day = ins[0][temp] - 'A' + 1;
    temp++;
    while (ins[0][temp] != ins[1][temp] || !(ins[0][temp] >= 'A' && ins[0][temp] <= 'N' || ins[0][temp] >= '0' && ins[0][temp] <= '9')) //hour A-N
        temp++;
    char c = ins[0][temp];
    if (c >= '0' && c <= '9')
        hour = c - '0';
    else
        hour = c - 'A' + 10;
    temp = 0;
    while (ins[2][temp] != ins[3][temp] || !(ins[2][temp] >= 'A' && ins[2][temp] <= 'Z' || ins[2][temp] >= 'a' && ins[2][temp] <= 'z')) //sec
    {
        temp++;
    }
    printf("%s %02d:%02d", days[day - 1].c_str(), hour, temp);
    return 0;
}