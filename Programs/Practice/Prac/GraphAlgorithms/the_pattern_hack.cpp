#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n = 3;

    long long arr[n] = {2224, 5262, 223};

    sort(arr, arr + n);
    cout << arr[0] + arr[n - 1];
    return 0;
}