#include <bits/stdc++.h>
using namespace std;
//function to subtract number
//without using '-' operator
int subtractWithoutOperator(int a,int b)
{
    while(b!=0)
      {
          int borrow=~a&b;
          a=a^b;
          //b=borrow*2
          b=borrow<<1;
      }
    return a;
}
int main()
{
    int a=7,b=8;
    int subtract=subtractWithoutOperator(a,b);
    cout<<"Subtract is ";
    cout<<subtract<<"\n";
    return 0;
}