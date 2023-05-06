#include <bits/stdc++.h>
using namespace std;

long long rev(long long x)
{
    long long rev = 0;
    while (x > 0)
    {
        int temp = x % 10;
        rev = rev * 10 + temp;
        x = x / 10;
    }
    return (rev);
}

int beautifulDays(int i, int j, int k)
{
    int no = 0, l;
    float m;
    for (l = i; l <= j; l++)
    {
        m = abs(l - rev(l));
        if (m / k == (int)m / k)
            no++;
    }
    return no;
}
int main()
{
    long long i = 20, j = 23, k = 6;

    cout << beautifulDays(i, j, k);
    return 0;
}
