#include <bits/stdc++.h>
using namespace std;

double absolute(double n) 
{
    if (n < 0)
        return (-1) * n;
    return n;
}
int main()
{
        double n = -28;
        double abs = absolute(n);
        cout<<"abs(n): " <<abs;
        return 0;
}
