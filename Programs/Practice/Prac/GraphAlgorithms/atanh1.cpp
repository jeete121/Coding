#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x = 0.45;

    double radian = atanh(x);
    double degrees = radian * 180 / 3.14;

    cout << degrees << "\n";

    return 0;
}