#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
  bool prime[11000000];
  
void seive2(){
//o nlog(logn)
    memset(prime, true, sizeof(prime)); 
  
  /*one optimization can be donw is that we can cancel 2 already*/
  for (ll p=2; p*p<=11000000; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=11000000; i += p) 
                prime[i] = false; 
        } 
    } prime[0]=0;
prime[1]=0;

}
     bool  isprime(ll n){
         //root n method
     for(ll i=2;i*i<=n;i++){
         if(n%i==0){
            return 0;
          
         }
     }return 1;
     }
int main(){
        seive2();
 
    
     
    ll t;
    cin>>t;
    while(t--){
ll n;
cin>>n;ll a[n];
f(i,0,n)cin>>a[i];

ll cnt=0;
for(int i=0;i<n;i++){
    for(ll j=i+1;j<n;j++){
        if(prime[a[i]+a[j]]){
cnt++;
        }
    }
}
cout<<cnt<<endl;





    }



}