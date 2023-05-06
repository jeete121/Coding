/*
Problem: 
Given a list of n strings , each no longer than m characters, 
find all the duplicate strings and divide them long long into groups.
*/

/*
Time complexity: o(nm+nlogn);
*/

#include <bits/stdc++.h>
using namespace std;
long long int compute_hash(string s)
{
    long long int p=31;
    long long int m=1e9+9;
    long long int p_pow=1;
    long long int hash_value=0;
    for(long long int i=0;i<s.size();i++)
      {
          hash_value=(hash_value+(s[i]-'a'+1)*p_pow)%m;
          p_pow=(p_pow*p)%m;
      }
    return hash_value;
}
vector<vector<long long int>> group_identical_strings(vector<string> s)
{
    long long int n=s.size();
    vector<pair<long long int,long long int>> hashes(n);
    for(long long int i=0;i<n;i++)
       hashes[i]={compute_hash(s[i]),i};
    sort(hashes.begin(),hashes.end());
    vector<vector<long long int>> groups;
    for(long long int i=0;i<n;i++)
       {
           if(i==0||hashes[i].first!=hashes[i-1].first)
               groups.emplace_back();
          groups.back().push_back(hashes[i].second);
       }
    return groups;
}
int main()
{
    long long int n;
    cin>>n;
    vector<string> s;
    for(long long int i=0;i<n;i++)
       {
           string x;
           cin>>x;
           s.push_back(x);
       }
    vector<vector<long long int>> ans=group_identical_strings(s);
    for(int i=0;i<ans.size();i++)
      {
          for(int j=0;j<ans[i].size();j++)
             cout<<ans[i][j]<<" ";
          cout<<"\n";
      }
}