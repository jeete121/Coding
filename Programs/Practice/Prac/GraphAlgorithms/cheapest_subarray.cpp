#include <bits/stdc++.h>
using namespace std;

int cheapestSubarray(int n, int arr[])
{

    int res;
    res = arr[0] + arr[1];

    for (int i = 1; i < n - 1; i++)
    {
        res = min(res, arr[i] + arr[i + 1]);
    }
    return res;
}
int main()
{

    int n = 3;

    int arr[n] = {3, 4, 2};

    cout << cheapestSubarray(n, arr) << "\n";

    return 0;
}