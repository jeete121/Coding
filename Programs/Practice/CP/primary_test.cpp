/*
 To check a number is prime or not
 Time Complexity: O(sqrt(N))
*/
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x)
{
    if(x<2)
       return false;
    for(int d=2;d*d<=x;d++)
      {
          if(x%d==0)
             return false;
      }
  return true;
}
   
int main()
{
    int n;
    cin>>n;
    if(isPrime(n))
       cout<<"Number is prime\n";
    else
      cout<<"Number is not prime\n";
    return 0;
    
}