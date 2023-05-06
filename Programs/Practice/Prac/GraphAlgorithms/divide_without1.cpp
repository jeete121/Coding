#include <bits/stdc++.h>
using namespace  std;

// using recurring
int divideTwoRec(int a, int b)
{
  // if b=0 then
   if (b == 0)
      return 0;

  int sign = 1;
  // check for negative
   if (a * b < 0)
      sign = -1;
   // convert into positive
   a = abs(a);
   b = abs(b);
   // base condition
        if (a < b) {
            return 0;
        }
   // call recurring method
    return sign * (1 + divideTwoRec(a - b, b));
}

int main()
{
    int dividend = -15;
    int divisor = 5;
    int quotient = divideTwoRec(dividend, divisor);
    cout<<"Quotient is "<<quotient;
}