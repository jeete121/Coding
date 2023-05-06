#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
//function to multiply the cuurent
//and update the result array
//and find the new size of the 
//fatorial number
int multiply(int x, int res[], int res_size)
{
    int carry = 0;
   //iterate till the end of size
    for (int i=0; i<res_size; i++)
    {
        int p=res[i]*x+carry;
        res[i]=(res[i] * x + carry)%10;
        carry=p/10;   
    }
 
  //while carry>0 increment the size
  //and put the carry%10 into the res array
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }

    //return the new size
    return res_size;
}


int  bigPower(int x, int n) 
{
  //base case
  //any number power 0 is 1
  if(n==0)
      return 1;
     int res[MAX];
     int res_size = 0;
     int temp = x;
    while (temp != 0) 
     {
       res[res_size] = temp % 10;
        temp = temp / 10;
        res_size++;
     }
   for (int i = 2; i <= n; i++)
       res_size = multiply(x, res, res_size);
       int sum=0;
  for (int i = res_size - 1; i >= 0; i--)
     sum+=res[i];
    return sum;
}
 int main()
{
   int n=5;
   int arr[201][201];
   //precompute bigpower till 200
   for(int i=1;i<=200;i++)
     {
         for(int j=1;j<=200;j++)
           {
               arr[i][j]=bigPower(i,j);
           }
     }

     //find the maximum answer
     int ans=0;
     for(int i=1;i<=n;i++)
       {
          for(int j=1;j<=n;j++)
            {
                ans=max(ans,arr[i][j]);
            }
       }
    cout<<ans<<"\n";
    return 0;
} 
