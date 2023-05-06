#include <bits/stdc++.h>
using namespace std;

void trailingZerosInFactorial(long long m)
{
    long long n, k, c;

    long long z = m * 5;
    while (true)
    {
        c = 0;
        n = z;
        while (true)
        {
            k = n / 5;
            if (k == 0)
                break;
            c += k;
            n = n / 5;
        }
        if (c <= m)
            break;
        z = z - 5;
    }
    if (c == m)
    {
        cout << 5 << "\n";
        for (long long i = z; i < z + 5; i++)
            cout << i << " ";
    }
    else
        cout << "0";
    cout << "\n";
}
int main()
{

    long long m = 1;

    trailingZerosInFactorial(m);

    return 0;
}