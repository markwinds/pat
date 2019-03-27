#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node
{
    int id;
    int num;
};

vector<Node> ha;
Node node[] = {{1, 2}, {66, 5}, {2, 3}, {3, 4}, {9, 6}, {5, 7}, {2, 45}, {1, 1}, {2, 4}};

bool cmp(Node a, Node b)
{
    if (a.id != b.id)
        return a.id < b.id;
    return false;
}

int main()
{
    // char buf[50];
    // sscanf("iios/12DDWDFF@122", "%*[^o]%[^@]", buf);
    // printf("%s\n", buf);

    // printf("%d", atoi("+03"));
    string a = "113 4 5 66 ";
    char b[40];
    sscanf(a.c_str(), "%[1-9]", b);
    cout << b;

    return 0;
}

//3    -5 6 1