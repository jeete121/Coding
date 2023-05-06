#include <bits/stdc++.h>
using namespace std;

int maximumValue(int n)
{
    int arr[20];
    arr[0] = 20;
    arr[1] = 30;
    for (int i = 2; i < n; i += 2)
        arr[i] = arr[i - 2] * 2;
    for (int i = 3; i < n; i += 2)
        arr[i] = arr[i - 2] * 3;
    int max1 = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int ans = abs(arr[i] + arr[j]) + abs(arr[i] - arr[j]);
            max1 = max(ans, max1);
        }
    }
    return max1;
}
int main()
{

    int n = 5;

    cout << maximumValue(n) << "\n";

    return 0;
}