#include <bits/stdc++.h>
using namespace std;


//function to find the sum of array
//after K negation
int largestSumAfterKNegations(vector<int>& A, int K)
{
    //sort the array
    sort(A.begin(),A.end());
    
    //iterate till the end of the array
    //and K>0
    for(int i=0;i<A.size()&&K>0;i++)
         {
            //if negative number then make 
            //multiply by -1 and decrement k
            if(A[i]<0)
            {
                A[i]=-1*A[i];
                K--;
            }

            //else break
            else
                break;
         }
    int flag=0;
    for(int i=0;i<A.size();i++)
        {
            if(A[i]==0)
               {
                   flag=1;
                   break;
               }
        }
    sort(A.begin(),A.end());
       if(K>0)
        {
          K=K%2;  
          if(K>0&&flag==0)
                A[0]=-A[0];
        }
        int sum=0;

        //find the sum of array element
        for(int i=0;i<A.size();i++)
               sum+=A[i];
        return sum;
}
int main()
{
   vector<int> A ={4,2,3};
   int K = 1;
   int maximumSum=largestSumAfterKNegations(A,K);
   cout<<maximumSum<<"\n";
   return 0;
}

