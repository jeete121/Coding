#include <bits/stdc++.h>
using namespace std;
//function which add two number 
//without using + operator
int addWithoutOperator(int a,int b)
{
    while(b!=0)
     {
         int carry=a&b;
         a=a^b;
         //b=carry*2
         b=carry<<1;
     }
     return a;
}
int main()
{
    int a=7,b=8;
    int sum=addWithoutOperator(a,b);
    cout<<"Sum is "<<sum<<"\n";
    return 0;
}