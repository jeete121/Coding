#include <bits/stdc++.h>
using namespace std;

int main()
{
    double degrees = 60;

    //convert degrees to radian
    double radian = degrees * 3.14 / 180;

    cout << cos(radian);

    return 0;
}