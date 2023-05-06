#include <bits/stdc++.h>
using namespace std;

//function to find the sum of all
//divisors of the number

//formula for sum
// (pow(p1,count1+1)-1/(p1-1))*...(pow(pn,countn+1)-1)/(pn-1)
int sumOfDivisors(int num)
{

    //intialize the sum as 1
    int sum=1;

    //varible to count the 
    //number of times a 
    //particular prime occurs
    int count=0;

    //count the number of times 
    //2 divides the given number
    while(num%2==0)
      {
          num=num/2;
          count++;
      }

    //update the sum
    //formula: sum=sum*((pow(2,count+1))-1)/(2-1)
    sum=sum*((pow(2,count+1))-1)/(2-1);
    for(int i=3;i*i<=num;i++)
      {
          count=0;
          
          //count number of times
          //the current prime divides the
          //number
          while(num%i==0)
           {
               num=num/i;
               count++;
           }
        //update the sum
          //formula: sum=sum*((pow(i,count+1))-1)/(i-1)
        sum=sum*((pow(i,count+1))-1)/(i-1);
      }
    
    //if num is greater than 1 then 
    //this is prime update the
    //sum
    if(num>1)
       sum=sum*((pow(num,2))-1)/(num-1);

    //retunr the final answer
    return sum;
}
int main()
{
    int num=24;
    int sum=sumOfDivisors(num);
    cout<<"Sum is ";
    cout<<sum<<"\n";
    return 0;
}