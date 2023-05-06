#include <bits/stdc++.h>
using namespace std;

//functoon to return GCD and find the 
//coefficient x any y
//of the equation a*x+b*y=gcd(a,b)
long long int gcd(long long int a,long long int b,long long int &x,long long int &y)
{

    //base case
    if(b==0)
     {
         //set x=1 
         x=1;

         //set y=0
         y=0;
         return a;
     }
     
     //intermediate variables
     long long int x1,y1;

     //now call the gcd function 
     long long int d=gcd(b,a%b,x1,y1);

     //formaula for x as x= y1
     x=y1;

     //formula for  y as x1-y1*(a/b)
     y=x1-y1*(a/b);
    
    //return the gcd
     return d;
}
int main()
{
    long long int a=10,b=24;
    long long int x,y;
    long long int d=gcd(a,b,x,y);
    cout<<d<<"\n";
    cout<<x<<" "<<y<<"\n";
}

//Time Complexity: O(log(min(a,b)))