#include <bits/stdc++.h>
using namespace std;

int theSavior(int n, int arr[])
{

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] != arr[j])
            {
                if (arr[i] % 2 == 0 && arr[j] % 2 == 0)
                    cnt++;
                if (arr[i] % 2 != 0 && arr[j] % 2 != 0)
                    cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    int n = 4;

    int arr[n] = {1, 2, 3, 4};

    cout << theSavior(n, arr) << "\n";

    return 0;
}