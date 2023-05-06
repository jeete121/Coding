/*
 Prime factorization of a number N
 Time Complexity: O(sqrt(N))
*/
#include <bits/stdc++.h>
using namespace std;
vector<long long > trial_division1(long long n)
{
    vector<long long> factorization;
    for(long long d=2;d*d<=n;d++)
       {
           while(n%d==0)
            {
                factorization.push_back(d);
                n/=d;
            }
       }
    if(n>1)
       factorization.push_back(n);
    return factorization;
}
int main()
{
  long long n;
  cin>>n;
  vector<long long > res=trial_division1(n);
  for(int i=0;i<res.size();i++)
     cout<<res[i]<<" ";
 return 0;
}