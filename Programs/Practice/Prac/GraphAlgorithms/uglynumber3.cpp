#include <bits/stdc++.h>
using namespace std;

//function to find the lcm of
//two numbers
long long lcm(long long a, long long b)
{
    return a * b / __gcd(a, b);
}

//function to find the nth ugly
//number
long long nthUglyNumber(long long n, long long a,
                        long long b, long long c)
{
    long long l = 1;
    long long r = 2000000000;
    long long ans;
    while (l <= r)
    {

        //calculate the mid point
        long long mid = l + (r - l) / 2;
        long long cnt = 0;
        cnt = cnt + mid / a;
        cnt = cnt + mid / b;
        cnt = cnt + mid / c;
        cnt = cnt - mid / lcm(a, b);
        cnt = cnt - mid / lcm(b, c);
        cnt = cnt - mid / lcm(a, c);
        cnt = cnt + mid / (lcm(c, lcm(a, b)));

        //update l
        if (cnt < n)
        {
            l = mid + 1;
        }

        //update r
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 3, a = 2, b = 3, c = 5;

    cout << nthUglyNumber(n, a, b, c);

    return 0;
}