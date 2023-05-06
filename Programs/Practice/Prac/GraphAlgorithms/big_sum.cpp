#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int i;

    long long int a[n] = {1000000001, 1000000002, 1000000003, 1000000004, 1000000005};
    long long int sum = 0;

    for (i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    cout << sum;
    return 0;
}
