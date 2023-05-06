#include <bits/stdc++.h>
using namespace std;

int perfectNumber(int n)
{
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                sum += n / i;
            else
                sum += n / i + i;
        }
    }
    return sum;
}
bool checkPerfectNumber(int num)
{
    if (num == 0)
        return false;
    int res = perfectNumber(num);
    if (res - num == num)
        return true;
    return false;
}

int main()
{
    int n = 28;
    if (checkPerfectNumber(n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}