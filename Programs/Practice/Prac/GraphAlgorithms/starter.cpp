#include <bits/stdc++.h>
using namespace std;

long long starter(long long n)
{

    long long cnt = 0;
    n = n - 1;
    long long sum3 = (n / 3) * (2 * 3 + (n / 3 - 1) * 3) / 2;
    long long sum5 = (n / 5) * (2 * 5 + (n / 5 - 1) * 5) / 2;
    long long sum15 = (n / 15) * (2 * 15 + (n / 15 - 1) * 15) / 2;
    cnt = sum3 + sum5 - sum15;
    return cnt;
}
int main()
{

    long long n = 10;

    cout << starter(n) << "\n";

    return 0;
}