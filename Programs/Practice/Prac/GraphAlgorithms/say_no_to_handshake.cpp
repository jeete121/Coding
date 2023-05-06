#include <bits/stdc++.h>
using namespace std;

int noHandshakes(int n)
{
    int res = n * (n - 1) / 2;
    return res;
}
int main()
{

    int n = 2;
    cout << noHandshakes(n);

    return 0;
}