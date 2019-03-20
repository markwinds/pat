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
    sort(node, node + 9, cmp);

    for (int i = 0; i < 9; i++)
    {
        cout << node[i].id << " " << node[i].num << endl;
    }

    return 0;
}