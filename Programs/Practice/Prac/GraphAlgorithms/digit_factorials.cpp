#include <bits/stdc++.h>
using namespace std;

//function to find the factorial of
//the given number
int fact(int n)
{
    if(n<=1)
       return 1;
    return n*fact(n-1);
}

//function to check  if 
//sum of factorial is
//divisible by the number
bool isSumFact(int n)
{
    int num=n;
    int sum=0;
    while(n>0)
      {
          sum+=fact(n%10);
          n=n/10;
      }
    if(sum%num==0)
        return true;
    return false;
}
int main()
{
    int n=20;
    int sum=0;
    for(int i=10;i<=n;i++)
      {
          if(isSumFact(i))
            sum+=i;
      }
    cout<<sum<<"\n";
    return 0;
}
