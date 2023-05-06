#include <bits/stdc++.h>
using namespace std;

int main()
{
    double value = 58.98;

    double radian = atan(value);

    double degrees = 180 * radian / 3.14;
    cout << degrees;

    return 0;
}