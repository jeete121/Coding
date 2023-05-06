#include <bits/stdc++.h>
using namespace std;
//function which add two number 
//without using + operator
int addWithoutOperatorRecursion(int a,int b)
{
   if(b==0)
      return a;
   else 
     return addWithoutOperatorRecursion(a^b,(a&b)<<1);
}
int main()
{
    int a=7,b=8;
    int sum=addWithoutOperatorRecursion(a,b);
    cout<<"Sum is "<<sum<<"\n";
    return 0;
}