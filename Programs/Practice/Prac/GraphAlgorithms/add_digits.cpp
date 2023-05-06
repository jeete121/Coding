#include <bits/stdc++.h>
using namespace std;

//function to find adddgits
//till we get the single 
//digit
int addDigits(int num) 
{
    int x=0,n;
    while(true)
    {
        x=0;
        n=num;
       while(num)
       {
          x+=num%10;
          num=num/10;
       }
       if(x==n)
             break;
       num=x;
            
    }
        return x;
}
int main()
{
   int n=38;
   cout<<addDigits(n);
   return 0;
}

