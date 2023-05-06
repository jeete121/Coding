#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {3, 2, 4, 5, 6, 8, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        int leftSum = 0;
        for (int j = 0; j < i; j++)
        {
            leftSum = leftSum + arr[j];
        }
        int rightSum = 0;
        for (int j = i + 1; j < n; j++)
        {
            rightSum = rightSum + arr[j];
        }

        if (leftSum == rightSum)
        {
            cout << "Equilibrium index is " << i << "\n";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "No Equilibrium index\n";
    }
    return 0;
}