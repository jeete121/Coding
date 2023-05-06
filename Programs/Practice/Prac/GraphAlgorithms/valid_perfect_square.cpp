#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num)
{
    for (int i = 1; (long long int)i * i <= num; i++)
    {
        if ((float)num / i == i)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int num = 16;
    if (isPerfectSquare(num))
        cout << "true";
    else
        cout << "false";
    return 0;
}