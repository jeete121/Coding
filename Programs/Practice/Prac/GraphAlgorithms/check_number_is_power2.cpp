#include <bits/stdc++.h>
using namespace std;


//function to check for
//power of 2
bool isPowerOfTwo(int n) 
{
    //base case
    if(n==0)
        return false;
   //itearte till n is not 1 or n 
   
   while(n!=1)
        {

            //if number is odd then not
            //power of 2 return false
            if(n&1)
                  return false;
          
          //else divide by 2
            n=n/2;
        }

     //return true
        return true;
}
int main()
{
    int num=4;

    if(isPowerOfTwo(num))
       cout<<"Power of 2\n";
    else
      cout<<"Not power of 2\n";
    return 0;
}
//Time Complexity: O(log(n))