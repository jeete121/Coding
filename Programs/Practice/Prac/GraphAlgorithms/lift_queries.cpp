#include <bits/stdc++.h>
using namespace std;

int a, b;
void liftQueires(int n)
{
    int x = abs(n - a);
    int y = abs(b - n);

    if (x <= y)
    {
        cout << "A\n";
        a = n;
    }
    else
    {
        cout << "B\n";
        b = n;
    }
}
int main()
{

    a = 0, b = 7;

    int n = 3;

    liftQueires(n);

    return 0;
}