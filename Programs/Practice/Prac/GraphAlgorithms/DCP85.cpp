#include <bits/stdc++.h>
using namespace std;

int bitOpertion(int x, int y, int b)
{
    b = -b;

    return (x & b) | (y & ~b);
}

int main()
{
    int x = 10, y = 24;
    int b = 1;

    cout << bitOpertion(x, y, b);
    return 0;
}
