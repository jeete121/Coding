#include <bits/stdc++.h>
using namespace std;
//Function to check given number is
//armstrong or not
bool isArmstrong(int num)
{
    int n=num;
    //length of number
    int length=log10(num)+1;
    int arm=0;
    while(n>0)
      {
          int mod=n%10;
          arm=arm+pow(mod,length);
          n=n/10;
      }
    if(arm==num)
       return true;
    else
      return false;
}
int main()
{
    int num=153;
    if(isArmstrong(num))
       cout<<"Number is Armstrong\n";
    else 
      cout<<"Number is not Armstrong\n";
} 