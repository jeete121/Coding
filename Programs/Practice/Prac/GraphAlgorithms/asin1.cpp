#include <bits/stdc++.h>
using namespace std;

int main()

{
    double value = 0.30;

    double radian = asin(value);

    double degrees = radian * 180 / 3.14;
    cout << degrees;

    return 0;
}