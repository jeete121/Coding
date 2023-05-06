#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    int arr[n] = {7, 4, 3, 5, 6, 2};

    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > x)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = x;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
