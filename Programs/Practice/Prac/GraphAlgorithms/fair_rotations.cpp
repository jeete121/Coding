#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int arr[n] = {2, 3, 4, 5, 6}, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int i = 0, cnt = 0;
    if (sum & 1)
    {
        cout << "NO\n";
    }
    else
    {
        while (i < n)
        {
            if (arr[i] & 1)
            {
                arr[i] += 1;
                arr[i + 1] += 1;
                i++;
                cnt += 2;
            }
            else
                i++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
