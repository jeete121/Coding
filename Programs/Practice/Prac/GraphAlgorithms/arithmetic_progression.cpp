#include <bits/stdc++.h>
using namespace std;

long long arithProgression(long long a, long long b, long long c)
{
    long long ans = abs(2 * b - (a + c));
    return (ans + 1) / 2;
}
int main()
{
    long long a = -5, b = 7, c = 6;

    cout << arithProgression(a, b, c);

    return 0;
}