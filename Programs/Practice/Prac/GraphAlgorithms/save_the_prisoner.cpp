#include <bits/stdc++.h>
using namespace std;

int saveThePrisoner(int n, int m, int s)
{

    return (m + s - 2) % n + 1;
}

int main()
{
    int n = 7, m = 19, s = 2;
    cout << saveThePrisoner(n, m, s);
    return 0;
}