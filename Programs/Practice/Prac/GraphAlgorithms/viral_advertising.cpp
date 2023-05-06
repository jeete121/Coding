#include <bits/stdc++.h>
using namespace std;

int viralAdvertising(int n)
{
    int sum = 0, x = 5, y = 3;
    for (int i = 1; i <= n; i++)
    {
        x = x / 2;
        sum += x;
        x = x * y;
    }
    return sum;
}

int main()
{
    int n = 5;
    cout << viralAdvertising(n);
    return 0;
}