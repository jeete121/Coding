#include <bits/stdc++.h>
using namespace std;

void raghuAndSayan(int a, int b, int n, int arr[])
{

    sort(arr, arr + n);
    int i = 0;
    while (i < n && a > 0)
    {
        a = a - arr[i];
        if (a >= 0)
            i++;
    }
    int j = 0;
    while (j < n && b > 0)
    {
        b = b - arr[j];
        if (b >= 0)
            j++;
    }
    if (i == j)
        cout << "Tie\n";
    else if (i > j)
        cout << "Raghu Won\n";
    else
        cout << "Sayan Won\n";
}
int main()
{
    int a = 10, b = 20, n = 3;

    int arr[n] = {10, 5, 4};

    raghuAndSayan(a, b, n, arr);

    return 0;
}