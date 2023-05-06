#include <bits/stdc++.h>
using namespace std;

// Using bit manipulation
int divideTwoUsingBit(int dividend,
                     int divisor)
{
    // hold for perform operation
    int denom = divisor;
    int current = 1;
   int answer = 0;
   
    // base case
    if (denom > dividend)
         return 0;
   // base case
    if (denom == dividend)
            return 1;

   // Left shift untill denom <=dividend
        while (denom <= dividend) {
            // one left shift
            denom <<= 1;
            current <<= 1;
     }
     // one right shift
    denom >>= 1;
    current >>= 1;
    // iterate untill current!=0
    while (current != 0) {
        if (dividend >= denom) {
                dividend = dividend - denom;
                // XOR
                answer = answer | current;
            }
        // right shift
            current >>= 1;
            denom >>= 1;
    }
        return answer;
}

int main()
{
    int dividend = -15;
    int divisor = 5;
    int sign = 1;
    if (dividend * divisor < 0) {
            sign = -1;

      }
  dividend =abs(dividend);
  divisor =abs(divisor);
  int quot = sign * divideTwoUsingBit(dividend, divisor);
  cout<<"Quotient is "<< quot;
  return 0;

}