#include <bits/stdc++.h>
using namespace std;

bool isThree(int n)
{

    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {

        //if i is the divisor of n
        if (n % i == 0)
        {

            //if n/i and i are same
            if (n / i == i)
            {
                cnt++;
            }
            else
                cnt += 2;
        }
    }
    if (cnt == 3)
        return true;
    return false;
}
int main()
{
    int n = 4;

    if (isThree(n))
        cout << "true\n";

    else
        cout << "false\n";

    return 0;
}