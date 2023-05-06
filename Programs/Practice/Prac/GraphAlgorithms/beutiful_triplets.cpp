#include <bits/stdc++.h>
using namespace std;

int beautifulTriplets(int arr[], int n, int d)
{
    int cnt = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        bool pos1 = binary_search(arr, arr + n, arr[i] + d);
        bool pos2 = binary_search(arr, arr + n, arr[i] + 2 * d);
        if (pos1 == true && pos2 == true)
            cnt++;
    }
    return cnt;
}
int main()
{
    int n = 7, d = 3;
    int arr[n] = {1, 2, 4, 5, 7, 8, 10};

    cout << beautifulTriplets(arr, n, d);
    return 0;
}
