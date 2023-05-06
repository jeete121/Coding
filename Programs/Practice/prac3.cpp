#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define mod 1000000007
ll dp[1010][1010];
ll find(ll n,ll l){
if(n==0){
    return 1;
}
if(dp[n][l]!=-1){
    return dp[n][l];
}
ll count=0;
for(int i=2;i<=min(n,l);i=i+2){
count=(count+find(n-i,l))%mod;
}
return dp[n][l]=count%mod;

}
int main(){
    ll t;
    cin>>t;
    while(t--){
ll n,l;
cin>>n>>l;
if(n%2==1){
    cout<<"0"<<endl;
    continue;
}
f(i,0,n+1){
    f(j,0,l+1){
        dp[i][j]=-1;
    }
}
cout<<find(n,l)%mod<<endl;






    }



}