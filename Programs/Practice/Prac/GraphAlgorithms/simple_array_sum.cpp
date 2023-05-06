#include <bits/stdc++.h>
using namespace std;
int main()

{
    int n = 6;

    int arr[n] = {1, 2, 3, 4, 10, 11};

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << sum << "\n";
    return 0;
}