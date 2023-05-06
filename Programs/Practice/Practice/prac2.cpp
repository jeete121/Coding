#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long  h,m,t;
    cin>>t;
    while(t--)
    {
        cin>>h>>m;
        long long res=(24-h)*60-m;
        cout<<res<<"\n";
    }

}
