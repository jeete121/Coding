#include <bits/stdc++.h>
using namespace std;
vector<long long int> rabin_karp(string const &s,string const &t)
{
 long long int p=31;
 long long int m=1e9+9;
 long long int S=s.size();
 long long int T=t.size();
 vector<long long int> p_pow(max(T,S));
 p_pow[0]=1;
 for(long long int i=1;i<p_pow.size();i++)
    p_pow[i]=(p_pow[i-1]*p)%m;
  vector<long long int> hash1(T+1,0);
  for(long long int i=0;i<T;i++)
     hash1[i+1]=(hash1[i]+(t[i]-'a'+1)*p_pow[i])%m;
  long long int hs=0;
  for(long long int i=0;i<S;i++)
     hs=(hs+(s[i]-'a'+1)*p_pow[i])%m;
  vector<long long int> occurrences;
  for(long long int i=0;i<=T-S;i++)
    {
       long long int curr_h=(hash1[i+S]+m-hash1[i])%m;
       if(curr_h==(hs*p_pow[i])%m)
          occurrences.push_back(i);
    }
    return occurrences;
}
 int main()
{
  string  pat,text;
  cin>>text>>pat;
  vector<long long int> v=rabin_karp(pat,text);
  for(long long int i=0;i<v.size();i++)
      cout<<v[i]<<" ";
  cout<<"\n";
  return 0;
}