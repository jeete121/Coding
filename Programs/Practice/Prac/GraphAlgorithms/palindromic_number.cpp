#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(int n)
{
    int res = 0;
    int y = n;
    while (y)
    {
        res = res * 10 + y % 10;
        y = y / 10;
    }
    if (n == res)
        return true;
    return false;
}

int countPalindromes(int a, int b)
{
    int cnt = 0;
    for (int i = a; i <= b; i++)
    {
        if (ispalindrome(i))
            cnt++;
    }
    return cnt;
}
int main()
{

    int a = 10, b = 20;

    cout << countPalindromes(a, b) << "\n";

    return 0;
}