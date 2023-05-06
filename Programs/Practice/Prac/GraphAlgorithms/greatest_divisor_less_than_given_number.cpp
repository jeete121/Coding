#include <bits/stdc++.h>
using namespace std;

//function to find the greatest divisor
//which is less than or equal to other number
int greatestDivisorLessThanK(int n,int k)
{
    int ans=-1;

    //find all divisors of the number
    for(int i=1;i*i<=n;i++)
     {
         if(n%i==0)
           {

               //if the number is same
               if(n/i==i)
                 {
                     //update answer
                     if(n/i<=k)
                        {
                          ans= max(ans,n/i);
                        }
                 }
                else
                {
                    //update answer
                    if(n/i<=k)
                      {
                          ans=max(ans,n/i);
                      }
                    //update answer
                    else if(i<=k)
                    {
                        ans=max(ans,i);
                    }
                    
                }
                
           }
     }
     return ans;
}
int main()
{
    int n=24;
    int k=7;
    cout<<greatestDivisorLessThanK(n,k);
    return 0;
}