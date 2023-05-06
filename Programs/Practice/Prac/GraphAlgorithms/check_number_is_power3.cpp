#include <bits/stdc++.h>
using namespace  std;

//function to check for
//power if 3   
bool isPowerOfThree(int num) 
{

    //base case
    if(num==0)
      return false;
    
    //iterate till the number becomes 1
    while(num!=1)
      {

          //if  number is not
          //divisible by 3
          //then return false
           if(num%3!=0)
                 return false;

          //else divide the number by 3
           num=num/3;
      }
        

   //number is power of 3
   //return true
   return true;

}
int main()
{
    int num=9;
    if(isPowerOfThree(num))
      cout<<"Power of 3\n";
    else
     cout<<"Not power of 3\n";

    return 0;
}
