#include <stdio.h>
int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
long int findlcm(int arr[], int n)
{
    long int ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = ((arr[i] * ans) /
               gcd(arr[i], ans));

    return ans;
}
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = gcd(arr[i], result);

    return result;
}

int main()
{

    int n = 2, m = 3, i, j, k, y, no = 0, q;
    long int x;
    int a[n] = {2, 4}, b[m] = {16, 32, 96};

    x = findlcm(a, n);
    y = findGCD(b, m);
    q = y / x;
    for (i = 1; i <= q; i++)
    {
        if (q % i == 0)
        {
            no++;
        }
    }
    printf("%d", no);
    return 0;
}
