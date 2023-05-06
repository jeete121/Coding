#include <bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor)
{

    //set the sign varibale according
    //to the given values
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    //n is absoulte value of divident
    long long int n = abs(dividend);

    // m is absolute value of divisor
    long long int m = abs(divisor);
    long long int temp = 0;
    long long int q = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (temp + (m << i) <= n)
        {
            temp += m << i;
            q = q | (1ll << i);
        }
    }

    //update sign of q
    q = (sign < 0) ? -q : q;
    return (q >= INT_MAX || q < INT_MIN) ? INT_MAX : q;
}

int main()
{
    int dividend = 10, divisor = 3;

    cout << divide(dividend, divisor);

    return 0;
}