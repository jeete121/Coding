#include <bits/stdc++.h>
using namespace std;

long long findComplement(long long n)
{
    long long binaryNum[32];
    long long i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (long long j = i - 1; j >= 0; j--)
    {
        if (binaryNum[j] == 1)
            binaryNum[j] = 0;
        else
            binaryNum[j] = 1;
    }
    long long x = 1, res = 0;
    for (long long j = 0; j <= i - 1; j++)
    {
        res = res + binaryNum[j] * x;
        x = x * 2;
    }
    return res;
}

int main()
{
    int num = 5;

    cout << findComplement(num);

    return 0;
}