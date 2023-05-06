#include <bits/stdc++.h>
using namespace std;

//hold the block sum
int f[1001];

//varibalw to hold the block counts
int BLK;

//function to find the minimum in the given
//range 
int getSum(int l,int r,int arr[])
{
    int LB=l/BLK;
    int RB=r/BLK;
    int min1=INT_MAX;
    int sum=0;

    //if lb is same as rb
    //then sum each elements 
    //one by one
    if(LB==RB)
       {
           for(int i=l;i<=r;i++)
              {
                  sum+=arr[i];
              }
       }
    else
    {

        //sum l to BLk*(LB+1)-1 
        for(int i=l;i<BLK*(LB+1);i++)
            {
                sum+=arr[i];
            }
        //sum the blocks which comes in the 
        //given range
        for(int i=LB+1;i<RB;i++)
            {
                 sum+=f[i];
            }
        //sum the remaining elements till r
        for(int i=BLK*RB;i<=r;i++)
          {
               sum+=arr[i];
          }
    }
   return sum;
}
int main()
{
    int arr[]={3,1,4,2,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int len=(int)sqrt(n)+1;
    BLK=len;
   for(int i=0;i<len;i++)
       f[i]=0;
    //store the block value
    for (int i=0; i<n; ++i)
       {
        f[i / len] = f[i/len]+arr[i];
       }
    int q=3;
    cout<<getSum(1,3,arr)<<"\n";
    cout<<getSum(3,5,arr)<<"\n";
    cout<<getSum(0,5,arr)<<"\n";
    return 0;
}