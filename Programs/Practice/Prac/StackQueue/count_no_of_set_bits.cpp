#include <bits/stdc++.h>
using namespace std;

//function to find the set
//bits of the given number
int countOfSetBits(int n)
{
    int count=0;

    //iterate till the number 
    //beomes 0
    while(n>0)
     {

         //if the bit is set
         //increment the count
         if(n&1)
           count++;
        //move to the next bit
         n=n/2;
     }
    //return the count of set bits
    return count;
}
int main()
{
    //1010
    int n=10;
    int setbit=countOfSetBits(n);
    cout<<"Set bits are ";
    cout<<setbit<<"\n";
    return 0;
}
//Time Complexity: O(log(n))