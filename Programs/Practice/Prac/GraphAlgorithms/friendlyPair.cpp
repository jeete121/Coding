#include <bits/stdc++.h>
using namespace std;

bool isFriendlyPair(int num1, int num2)
{

    int sumDivisors1 = 0, sumDivisors2 = 0;

    //find sum of divisors of first number
    for (int i = 1; i < num1; i++)
    {
        if (num1 % i == 0)
        {
            sumDivisors1 += i;
        }
    }

    // find sum of divisors of second number
    for (int i = 1; i < num2; i++)
    {
        if (num2 % i == 0)
        {
            sumDivisors2 += i;
        }
    }

    if (sumDivisors1 == num1 && sumDivisors2 == num2)
        return true;
    else
        return false;
}
int main()
{
    int num1 = 28, num2 = 6;

    if (isFriendlyPair(num1, num2))
        cout << "Friendly Pair";
    else
        cout << "Not a Friendly Pair";

    return 0;
}