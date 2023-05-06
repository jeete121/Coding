#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    int quotient = 0;
    bool neg = false;

    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
    {
        neg = true;
    }

    dividend = abs(dividend);
    divisor = abs(divisor);

    if (dividend < divisor)
    {
        return 0;
    }
    else if (dividend > 0 && divisor != 0)
    {
        while (dividend >= divisor)
        {
            dividend -= divisor;
            ++quotient;
        }
    }

    return neg ? -quotient : quotient;
}

int main()
{
    int num1 = 10, num2 = 5;

    cout << divide(num1, num2);

    return 0;
}