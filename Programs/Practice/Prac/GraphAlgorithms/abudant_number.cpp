#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 18;

    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum > n)
    {
        cout << "Abundant number\n";
    }
    else
    {
        cout << "Not abundant number\n";
    }
    return 0;
}