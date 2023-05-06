#include <bits/stdc++.h>
using namespace std;

/*
hash(s)=((s[0]+s[1]⋅p+s[2]⋅p^2+...+s[n−1]⋅p^n−1)mod)m
∑i=0n−1(s[i]⋅p^i)modm
*/
long long int compute_hash(string s)
{
    long long int p=31;
    long long int m=1e9+9;
    long long int hash_value=0;
    long long int p_pow=1;
    for(long long int i=0;i<s.size();i++)
        {
            hash_value=(hash_value+(s[i]-'a'+1)*p_pow)%m;
            p_pow=(p_pow*p)%m;
        }
    return hash_value;
}
int main()
{
   long long int t;
   cin>>t;
   while(t--)
     {
         string s;
         cin>>s;
         cout<<compute_hash(s)<<"\n";
     }
    return 0;
}