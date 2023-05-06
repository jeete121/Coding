/*
Problem: 
Given a string s of length n, consisting only of lowercase English 
letters, find the number of different substrings in this string.
*/
/*
 Time complexity : O(n^2logn)
*/
#include <bits/stdc++.h>
using namespace std;
long long int count_unique_substring(string s)
{
    long long int n=s.size();
    long long int p=31;
    long long int m=1e18+9;
    vector<long long int> p_pow(n);
    p_pow[0]=1;
    for(long long int i=1;i<n;i++)
       p_pow[i]=(p_pow[i-1]*p)%m;
    vector<long long int> hash1(n+1,0);
    for(long long int i=0;i<n;i++)
       hash1[i+1]=(hash1[i]+(s[i]-'a'+1)*p_pow[i])%m;
    long long int cnt=0;
    for(long long int len=1;len<=n;len++) 
      {
          set<long long int> hs;
          for(long long int i=0;i<=n-len;i++)
            {
                long long int curr_h=(hash1[i+1]-hash1[i]+m)%m;
                curr_h=(curr_h*p_pow[n-i-1])%m;
                hs.insert(curr_h);
            }
            cnt+=hs.size();
      }
      return cnt;
}
int main()
{
    string s;
    cin>>s;
    cout<<count_unique_substring(s)<<"\n";
    return 0;
}