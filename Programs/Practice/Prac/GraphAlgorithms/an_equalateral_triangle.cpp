#include <bits/stdc++.h>
using namespace std;

int equalateralTriangle1(int n)
{
    int ans = 0;
    for (int i = n - 2; i >= 1; i--)
    {
        if (i & 1)
        {
            int m = (n - i) / 2;
            int j = i * (i + 1) / 2;
            ans += j * m;
        }
        else
        {
            int m = (n - i - 1) / 2;
            int j = i * (i + 1) / 2;
            ans += j * m;
        }
    }
    return ans;
}
int equalateralTriangle(int n)
{
    int ans = 0;
    for (int i = n - 2; i >= 1; i--)
    {
        if (i & 1)
        {
            int m = (n - i - 1) / 2;
            int j = i * (i + 1) / 2;
            ans += j * m;
        }
        else
        {
            int m = (n - i) / 2;
            int j = i * (i + 1) / 2;
            ans += j * m;
        }
    }
    return ans;
}
int main()
{
    int n = 5;
    if (n & 1)
        cout << equalateralTriangle1(n) << "\n";
    else
        cout << equalateralTriangle(n) << "\n";
    return 0;
}