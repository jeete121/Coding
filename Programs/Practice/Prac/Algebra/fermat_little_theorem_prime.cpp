#include <bits/stdc++.h>
using namespace std;
//This function for find (a*b)%c for big numbers
//Time O(log(b))
long long int mul(long long int a,long long b,long long c)
{
  a=a%c;
  long long int  res=0;
  while(b)
   {
      if(b&1)
          res=(res+a)%c;
      a=(a*2LL)%c;
      b=b/2;
   }
   return res%c;
}
//This function to find (a^n)%mod for big numbers 
//Time O(log(n))
long long int  binpower(long long int base, long long int  e, long long int mod) {
   long long int res = 1;
    //base%=mod;
    while(e)
      {
         if(e&1)
            res=mul(res,base,mod);
         base=mul(base,base,mod);
         e=e/2;
      }
    return res%mod;
}
//This is Fermat little Theorem to check number is prime or not
//Time O(log(n))

bool isPrime(long long int n,long long int iter=5) 
{
    if (n <=4)
        return n == 2 || n == 3;

    for (long long int i = 0; i < iter; i++) {
        long long int a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
  long long int t;
  cin>>t;
  while(t--)
    {
       long long int n;
       cin>>n;
       if(isPrime(n))
          cout<<"YES\n";
       else
          cout<<"NO\n";
    }
   return 0;
}

