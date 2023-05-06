#include <bits/stdc++.h>
using namespace std;
//function to multiply two numbers
//without using * operator
int multiplicationTwoNum(int a,int b)
{
    if(b==0)
      return 0;
    if(b>0)
      return a+multiplicationTwoNum(a,b-1);
    if(b<0)
      return -multiplicationTwoNum(a,-b);
    return 0;
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