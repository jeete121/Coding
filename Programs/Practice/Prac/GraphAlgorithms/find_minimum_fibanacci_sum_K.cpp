#include <bits/stdc++.h>
using namespace std;


//function to count the minimum
//fibonacci numbers whose sum is k
long long findMinFibonacciNumbers(long long  k)
{
        long long  fib[50];
        fib[1]=1;
        fib[2]=1;
        for(long long  i=3;i<50;i++)
              fib[i]=fib[i-1]+fib[i-2];
        long long  i=1;
        while(k>=fib[i])
              i++;
        long long cnt=0;
        i=i-1;
       while(k)
         {
           while(fib[i]>k)
                 i--;
           k=k-fib[i];
          cnt++;
         }
        return cnt;
}

int main()
{
    int k = 19;
    cout<<findMinFibonacciNumbers(k);
    return 0;
}