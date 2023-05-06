#include <bits/stdc++.h>
using namespace std;

void fredoGame(int sum, int n, int a[])
{
    int flag = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            sum -= 1;
        }
        else
        {
            sum += 2;
        }
        if (sum == 0 && i < n - 1)
        {
            flag = 1;
            ans = i + 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Yes"
             << " " << sum << "\n";
    else
        cout << "No"
             << " " << ans << "\n";
}
int main()
{
    int sum = 5, n = 5;

    int a[n] = {0, 0, 1, 0, 1};

    fredoGame(sum, n, a);

    return 0;
}