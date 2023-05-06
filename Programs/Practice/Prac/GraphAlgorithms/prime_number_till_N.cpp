#include <bits/stdc++.h>
using namespace std;
//function to check
//given number is prime
bool isPrime(int n)
{
    for(int i=2;i<n;i++)
     {
         //if n is divisible by any number
         //other tha 1 and n then not prime
         if(n%i==0)
            return false;
     }
    return true;
}
vector<int> primeTillN(int n)
{
    vector<int> prime;
    for(int i=2;i<=n;i++)
      {
          if(isPrime(i))
             prime.push_back(i);
      }
    return prime;
}
int main()
{ 
    int num=10;
    vector<int> prime=primeTillN(num);
    for(int i=0;i<prime.size();i++)
       cout<<prime[i]<<" ";
    return 0;
}
//Time Complexity:O(n^2)
//Space Complexity:O(n)