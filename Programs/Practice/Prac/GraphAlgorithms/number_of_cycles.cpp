#include <bits/stdc++.h>
using namespace std;

int numbOfCycles(int n)
{
    long long ans = n * (n - 1) + 1;
    return ans;
}
int main()
{
    long long n = 4;

    cout << numbOfCycles(n) << "\n";
    return 0;
}