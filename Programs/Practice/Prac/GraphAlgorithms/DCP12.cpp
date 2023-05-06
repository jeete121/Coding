#include <bits/stdc++.h>
using namespace std;

int countWays(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return countWays(n - 1) + countWays(n - 2);
}
int main()
{
    int n = 4;
    cout << countWays(n);

    return 0;
}