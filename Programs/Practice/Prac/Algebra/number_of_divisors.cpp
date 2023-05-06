#include <bits/stdc++.h>
using namespace std;


//function to find the number of
// divisors of given number
//formula of number of divisors
// (p1+1)*(p2+1)*(p3+1)*...(pn+1)
//where pi are the count of different prime 
//fatcors of the given number
int divisorsCount(int num)
{

    //initialize the divisors as 1
    int divisors=1;
    int count=0;

    //count the number of 
    //times 2 divides the number
    while(num%2==0)
    {
        count++;
        num=num/2;

    }

    //update the divisors
    //formula =divisors*(count+1)
   divisors=divisors*(count+1);

   //now iterare for other numbers
   for(int i=3;i*i<=num;i+=2)
     {
         count=0;
         //while the number is divisible
         //by current prime count 
         //the no of times it divides
         while(num%i==0)
          {
              num=num/i;
              count++;
          }

    
    //update the divisors
    //formula =divisors*(count+1)
          divisors=divisors*(count+1);
     }

     //if  number not become 1
     //then it  is prime
     //then update the answer
    if(num>1)
       divisors=divisors*2;

    //return the count of divisors
    return divisors;
}
int main()
{
    int num=24;
    int divisors=divisorsCount(num);
    cout<<"Number of divisors ";
    cout<<divisors<<"\n";
}