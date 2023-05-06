#include <bits/stdc++.h>
using namespace std;

string dayOfProgrammer(int y)
{

    int sum1, sum2, d, sum3;
    string res = "";
    if (y > 1918)
    {
        if ((y % 400 == 0) || (y % 4 == 0 && !(y % 100 == 0)))
        {
            sum1 = 244;
            d = 256 - sum1;
        }
        else
        {
            sum2 = 243;
            d = 256 - sum2;
        }
    }
    else if (y < 1918)
    {
        if (y % 4 == 0)
        {
            sum1 = 244;
            d = 256 - sum1;
        }
        else
        {
            sum1 = 243;
            d = 256 - sum1;
        }
    }
    else if (y == 1918)
    {
        sum3 = 230;
        d = 256 - sum3;
    }
    res = to_string(d) + ".09." + to_string(y);
    return res;
}
int main()
{
    int y = 1800;
    cout << dayOfProgrammer(y);
    return 0;
}
