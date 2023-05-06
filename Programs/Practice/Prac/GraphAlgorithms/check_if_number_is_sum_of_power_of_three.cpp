#include <bits/stdc++.h>
using namespace std;

bool checkPowersOfThree(int n)
{

    while (n > 0)
    {
        if (n % 3 == 2)
            return false;
        n = n / 3;
    }
    return true;
}

int main()
{
    int n = 12;

    if (checkPowersOfThree(n))
        cout << "true";
    else
        cout << "false";

    return 0;
}