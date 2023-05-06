#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long arr[3],I[3][3],T[3][3];
void mul(long long A[3][3],long long B[3][3],long long dim)
{
    long long res[dim+1][dim+1];
    for(long long i=1;i<=dim;i++)
      {
          for(long long j=1;j<=dim;j++)
            {
                res[i][j]=0;
                for(long long k=1;k<=dim;k++)
                  {
                      long long x=(A[i][k]*B[k][j])%MOD;
                      res[i][j]=(res[i][j]+x)%MOD;
                  }
            }
      }
    for(long long i=1;i<=dim;i++)
      {
          for(long long j=1;j<=dim;j++)
             A[i][j]=res[i][j];
      }
}
long long getFib(long long n)
{
    if(n<=2)
        return arr[n];
    I[1][1]=I[2][2]=1;
    I[1][2]=I[2][1]=0;
    T[1][1]=0;
    T[1][2]=T[2][1]=T[2][2]=1;
    n=n-1;
    while(n)
      {
          if(n&1)
             {
                  mul(I,T,2);
                  n--;
             }
            else
            {
               mul(T,T,2);
               n=n/2;
            }
            
      }
    long long Fn=(arr[1]*I[1][1]+arr[2]*I[2][1])%MOD;
    return Fn;
}
int  main()
{
    long long t,a,b,n;
    cin>>t;
    while(t--)
      {
          cin>>arr[1]>>arr[2]>>n;
          n++;
          cout<<getFib(n)<<"\n";
        
      }
    return 0;
}