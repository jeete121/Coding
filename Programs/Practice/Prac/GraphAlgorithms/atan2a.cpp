#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x = 10.0, y = -5.0;

    double radian = atan2(y, x);

    double degrees = radian * 180 / 3.14;
    cout << degrees << "\n";

    return 0;
}