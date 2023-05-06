#include <bits/stdc++.h>
using namespace std;
int I[1001][1001],T[1001][1001];
int dim;
void mul(int A[][1001],int B[][1001])
{
    int res[dim+1][dim+1];
    for(int i=1;i<=dim;i++)
      {
          for(int j=1;j<=dim;j++)
            {
                  res[i][j]=0;
                  for(int k=1;k<=dim;k++)
                      res[i][j]+=A[i][k]*B[k][j];
            }
      }
      for(int i=1;i<=dim;i++)
         for(int j=1;j<=dim;j++)
            A[i][j]=res[i][j];
    
}
void fun(int n)
{
  for(int i=1;i<=dim;i++)
     {
         for(int j=1;j<=dim;j++)
           {
               if(i==j)
                  I[i][j]=1;
                else
                  I[i][j]=0;
                
           }
     }
    while(n)
     {
         if(n&1)
            mul(I,T),n--;
        else
            mul(T,T),n=n/2;
     }
}

int main()
{
    int n,m;
    cin>>n>>m;
    //int grid[n+1][n+1];
    memset(T,0,sizeof(T));
    dim=n;
   // cout<<dim<<"\n";
    while(m--)
      {
          int a,b;
          cin>>a>>b;
          T[a][b]++;
         // T[b][a]++;
      }
    // for(int i=1;i<=n;i++)
    //   {
    //       for(int j=1;j<=n;j++)
    //          cout<<T[i][j]<<" ";
    // //       cout<<"\n";
    //   }
       int k;
       cin>>k;
      fun(k);
      for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=n;j++)
                cout<<T[i][j]<<" ";
              cout<<"\n";
         }
    return 0;
}