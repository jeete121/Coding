#include <bits/stdc++.h>
using namespace std;

int squares(int a, int b)
{
    return (floor(sqrt(b)) - ceil(sqrt(a)) + 1);
}

int main()
{
    int a = 3, b = 9;
    cout << squares(a, b);
    return 0;
}