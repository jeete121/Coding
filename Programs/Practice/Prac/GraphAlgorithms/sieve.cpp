#include <bits/stdc++.h>
using namespace std;
//function to find all prime 
//till N
vector<int > primeNumberTillN(int n)
{
    bool prime[n+1];
    for(int i=0;i<n;i++)
       prime[i]=true;
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<=n;i++)
     {
         if(prime[i])
          {
              for(int j=i*i;j<=n;j+=i)
                 prime[j]=false;
          }
     }
     vector<int> primeNum;
     for(int i=2;i<=n;i++)
       {
           if(prime[i])
             primeNum.push_back(i);
       }
    return primeNum;
}
int main()
{
    int num=10;
    vector<int> prime=primeNumberTillN(num);
    for(int i=0;i<prime.size();i++)
       cout<<prime[i]<<" ";
    return 0;
}
//Time Complexity:O(nloglog(n))
//Space Complexity:O(n)
