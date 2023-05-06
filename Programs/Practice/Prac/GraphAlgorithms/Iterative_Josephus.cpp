#include <bits/stdc++.h>
using namespace std;
int josephus(int n,int k)
{
    int res=0;
    for(int i=1;i<=n;i++)
       res=(res+k)%i;
    return res+1;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<josephus(n,k)<<"\n";
    return 0;
}