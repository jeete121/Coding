#include <bits/stdc++.h>
using namespace std;
//function to check for 
//magic number
bool isMagic(int num)
{
  //itereate till num is a sigle digit number
    while(num>=10)
     {
         int temp=0;
         while(num>0)
           {
               temp+=num%10;
               num=num/10;
           }
         num=temp;
     }
    //if num with single digit and it is 1
    //then it is magic
    if(num==1)
       return true;
    //else not a magic number
    return false;
}
int main()
{
    int num=1234;
    if(isMagic(num))
       cout<<"Number is magic ";
    else
      cout<<"Not a magic number ";
   return 0;
}