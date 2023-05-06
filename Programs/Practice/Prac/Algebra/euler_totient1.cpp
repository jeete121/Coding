#include <bits/stdc++.h>
using namespace std;

//function to find the Euler
//Totient Value of the given 
//number count number from 1 10 n
//which are coprime with n
int eulerTotientFunction(int n)
{
    //initialize the reuslt as same 
    //as n
    int res=n;

    //iterate till the sqrt(n)
    for(int i=2;i*i<=n;i++) 
      {

          //if n is divisble by n
          if(n%i==0) 
           {
               //appy formula of EFF
               res/=i;
               res*=(i-1);
               while(n%i==0)
                  n=n/i;
           }
      }
    if(n>1)
      {
          res/=n;
          res*=(n-1);
      }
    return res;
}
int main()
{
    int n=16;
    int euler_to_value=eulerTotientFunction(n);
    cout<<"No of Coprimes are ";
    cout<<euler_to_value<<"\n";
    return 0;
}
//Time Complexity: O(sqrt(n))
//Space Complexity:O(1)