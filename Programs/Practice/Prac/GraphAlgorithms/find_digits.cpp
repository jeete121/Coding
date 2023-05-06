#include <iostream>
using namespace std;

int findDigits(int n)
{
    int i, m, j, l, k, no, x;
    m = n;
    x = n;
    l = 0;
    while (x > 0)
    {
        l++;
        x = x / 10;
    }
    long long a[l];
    j = 0;
    while (n > 0)
    {
        a[j] = n % 10;
        n = n / 10;
        j++;
    }
    no = 0;
    for (k = 0; k < l; k++)
    {
        if (a[k] != 0)
        {
            if (m % a[k] == 0)
                no++;
        }
    }
    return no;
}
int main()
{
    long long n = 12;
    cout << findDigits(n);
    return 0;
}
