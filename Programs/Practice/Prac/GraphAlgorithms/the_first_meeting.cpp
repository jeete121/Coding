#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];
void primeInitialize()
{

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
                prime[j] = false;
        }
    }
}

int theFirstMeeting(int n, int a[])
{
    sort(a, a + n);
    int i = 0, j = n - 1;
    int min1 = 1, max1 = 1;
    while (i < n)
    {
        if (prime[a[i]])
        {
            min1 = a[i];
            break;
        }
        i++;
    }
    while (j >= 0)
    {
        if (prime[a[j]])
        {
            max1 = a[j];
            break;
        }
        j--;
    }
    if (min1 == 1)
        return -1;
    else
        return max1 - min1;
}
int main()
{

    int n = 5;
    int a[n] = {1, 2, 3, 4, 5};

    primeInitialize();

    cout << theFirstMeeting(n, a) << "\n";

    return 0;
}