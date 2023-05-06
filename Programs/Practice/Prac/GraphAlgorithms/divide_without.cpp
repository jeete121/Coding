#include <bits/stdc++.h>
using namespace std;


// function to divide the number
int divideTwo(int dividend, int divisor) 
{
   int quotient = 0;
  // if divisor=0 then
  if (divisor == 0)
      return 0;

  int sign = 1; // plus sign
  // check negative sign
   if (dividend * divisor < 0) 
    {
            sign = -1;
        
    }
 // convert value into positive
  dividend = abs(dividend);
  divisor=abs(divisor);
  // iterate untill dividend>=divisor
  while (dividend >= divisor) {
       dividend = dividend - divisor;
       quotient++;
   }

  return quotient * sign;
}
int main()
{
    int dividend = -15;
    int divisor = 5;
    int quotient = divideTwo(dividend, divisor);
    cout<<"Quotient is "<<quotient;
}