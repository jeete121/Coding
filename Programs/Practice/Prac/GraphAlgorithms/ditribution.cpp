#include <bits/stdc++.h>
using namespace std;

int distribution(int n)
{
    int ans = 0;
    for (int i = n - 1; i > n / 2; i--)
    {
        ans += (n - i + 1) / 2;
    }
    for (int i = n / 2; i > n / 3; i--)
    {
        for (int j = i - 1; j > i / 2; j--)
        {
            int k = n - i - j;
            int cnt = 0;
            while (k < j)
            {
                cnt++;
                k++;
                j--;
            }
            ans += cnt;
        }
    }
    return ans;
}
int main()
{
    int n = 10;

    cout << distribution(n) << "\n";

    return 0;
}