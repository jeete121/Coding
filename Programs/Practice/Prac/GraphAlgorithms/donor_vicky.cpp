#include <bits/stdc++.h>
using namespace std;

int donorVicky(int n, int x)
{
    int i = 1;
    int ans;
    int j = 1;
    while (x > 0)
    {
        x = x - j;
        if (x <= 0)
        {
            ans = i;
            break;
        }
        if (i == n)
            i = 1;
        else
            i++;
        j++;
    }
    return ans;
}
int main()
{
    int n = 5, x = 4;

    cout << donorVicky(n, x) << "\n";

    return 0;
}