#include <bits/stdc++.h>
using namespace  std;

//function to check for
//power if 4    
bool isPowerOfFour(int num) 
{

    //base case
    if(num==0)
      return false;
    
    //iterate till the number becomes 1
    while(num!=1)
      {

          //if  number is not
          //divisible by 4
          //then return false
           if(num%4)
                 return false;

          //else divide the number by 4
           num=num/4;
      }
        

   //number is power of 4
   //return true
   return true;

}
int main()
{
    int num=64;
    if(isPowerOfFour(num))
      cout<<"Power of 4\n";
    else
     cout<<"Not power of 4\n";

    return 0;
}
