#include <bits/stdc++.h>
using namespace std;

int maxThree(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    if (b >= a && b >= c)
        return b;
    return c;
}
int main()
{
    int a = 8, b = 6, c = 1;

    cout << maxThree(a, b, c);

    return 0;
}