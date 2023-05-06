#include<bits/stdc++.h>
using namespace std;

// base value
double E = 10.0;
double log(double n) 
{
        double c = 0;
        while (n > 1) {
            n = n / E;
            c++;
        }
        c = c + n;
        return c - 1;
}
int main()
{
   double n = 50;
   double c = log(n);
   cout<<"log value of n approximately: " <<c;
    return 0;
}

