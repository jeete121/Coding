/*
 Prime Number between [1:N] Using Sieve Of Eratosthenes
 Time complexity: O(Nloglog(N))
 Space Complexity:O(N)
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<char> is_prime(n+1,true);
    is_prime[0]=false;
    is_prime[1]=false;
    for(int i=2;i<=n;i++)
      {
          if(is_prime[i]&&(long long)i*i<=n)
            {
                for(int j=i*i;j<=n;j+=i)
                   is_prime[j]=false;
            }
      }
    for(int i=1;i<=n;i++)
       if(is_prime[i])
          cout<<i<<" ";
    return 0;
}