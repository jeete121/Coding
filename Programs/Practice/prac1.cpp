#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,x,y) for(ll i=x;i<y;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
ll n,w,x,y;
cin>>n>>w>>x>>y;
ll wei[n+1];
ll val[n+1];
f(i,1,n+1){
    cin>>wei[i];
}

f(i,1,n+1){
    cin>>val[i];
}
ll an=0;
for(int q=0;q<n;q++){
    for(ll p=q+1;p<n;p++){
ll temp1=val[q];val[q]=val[q]*x;
ll temp2=val[p];val[p]=val[p]*y;
ll dp[n+1][w+1];
f(i,0,n+1){
  f(j,0,w+1){
    dp[i][j]=0;
  }
}
for(ll i=0;i<=n;i++){
  for(ll j=0;j<=w;j++){
    if (i == 0 || j == 0){ 
                dp[i][j] = 0;
                 continue;
     } 
    if(j-wei[i]<0){
     dp[i][j]=dp[i-1][j];
    }
    else{
     dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wei[i]]);
    }
  }
}
an=max(an,dp[n][w]);
val[q]=temp1;
val[p]=temp2;

 temp1=val[q];val[q]=val[q]*y;
 temp2=val[p];val[p]=val[p]*x;

f(i,0,n+1){
  f(j,0,w+1){
    dp[i][j]=0;
  }
}
for(ll i=0;i<=n;i++){
  for(ll j=0;j<=w;j++){
    if (i == 0 || j == 0){ 
                dp[i][j] = 0;
continue;
     } 
    if(j-wei[i]<0){
     dp[i][j]=dp[i-1][j];
    }
    else{
     dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wei[i]]);
    }
  }
}
 an=max(an,dp[n][w]);
 val[q]=temp1;
 val[p]=temp2;
    }
  }
  cout<<an<<endl;
    }
}
