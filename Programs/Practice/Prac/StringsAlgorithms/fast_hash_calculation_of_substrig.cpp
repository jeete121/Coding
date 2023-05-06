#include <bits/stdc++.h>
using namespace std;
long long int hash1[1000001];
long long int p_pow[1000001];
void compute_hash(string s)
{
    long long int n=s.size();
    long long int p=31;
    long long int m=1e9+9;
    p_pow[0] = 1;
    for (long long int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;
    for(long long int i=0;i<n;i++)
       hash1[i+1]=(hash1[i]+(s[i]-'a'+1)*p_pow[i])%m;
}
int main()
{
    string s;
    cin>>s;
    long long int q;
    cin>>q;
    compute_hash(s);
    while(q--)
     {
         long long int l,r;
         cin>>l>>r;
         cout<<hash1[r]*p_pow[r-l]-hash1[l-1]<<"\n";
     }
     return 0;

}