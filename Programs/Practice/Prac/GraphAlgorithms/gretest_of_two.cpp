#include <bits/stdc++.h>
using namespace std;
//funtion to find the greatest of 
//two number
int greaterOfTwo(int num1,int num2)
{
    if(num1>num2)
       return 1;
    else if(num2>num1)
       return 2;
    else
      return 0;
}
int main()
{
    int num1=13;
    int num2=15;
    int greater=greaterOfTwo(num1,num2);
    if(greater==1)
       cout<<"Greater is first number ";
    else if(greater==2)
       cout<<"Greater is second number ";
    else
      cout<<"Equal ";
    return 0;
}