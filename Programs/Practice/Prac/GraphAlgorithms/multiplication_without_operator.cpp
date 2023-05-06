#include <bits/stdc++.h>
using namespace std;
//function to multiply two numbers
//without using * operator
int multiplicationTwoNum(int a,int b)
{
    int mul=0;
    if(a==0||b==0)
       return mul;
    if(b>0)
     {
         while (b>0)
         {
            mul+=a;
            b--;
         }
         return mul;
         
     }
     if(b<0)
     {
         while(b<0)
          {
              mul+=a;
              b++;
          }
        return -mul;
     }
     return mul;
}
int main()
{
    int a=7;
    int b=8;
    int multiply=multiplicationTwoNum(a, b);
    cout<<"Multiplication is ";
    cout<<multiply<<"\n";
    return 0;
}