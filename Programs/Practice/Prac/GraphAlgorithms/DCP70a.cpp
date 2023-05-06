#include <bits/stdc++.h>
using namespace std;

int nthPerfectNumber(int n)
{
    int count = 0;
    int ans;
    for (int i = 1;; i++)
    {
        int x = i;
        int sumDigits = 0;

        while (x > 0)
        {
            int temp = x % 10;
            sumDigits += temp;
            x = x / 10;
        }
        if (sumDigits == 10)
            count++;
        if (count == n)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    int n = 4;

    cout << nthPerfectNumber(n);

    return 0;
}