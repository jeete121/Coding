#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x = 0.25;

    double radian = acos(x);

    double degrees = radian * 180 / 3.14;

    cout << degrees << "\n";

    return 0;
}