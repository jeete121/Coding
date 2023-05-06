#include <bits/stdc++.h>
using namespace std;

//function to find the  maximum 
//product subarray
int maxProduct(int arr[],int n) 
{
    //set varible max1 ,min1 and ans
    int max1=1,min1=1,ans=INT_MIN;

    //iterate till the end of
    //array
    for(int i=0;i<n;i++)
      {

          //if  current element is
          //negative then change swap min1 and max1
          if(arr[i]<0)
          {
              int f=min1;
              min1=max1;
              max1=f;
          }
          //update max1
          max1=max(arr[i],arr[i]*max1);

          //update min1
          min1=min(arr[i],min1*arr[i]);

          //update the answer
          ans=max(ans,max1);
      }

      //return the final answer
        return ans;
}
int main()
{
    int arr[]={2,3,-2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maximum=maxProduct(arr,n);
    cout<<"Maximum product is\n";
    cout<<maximum<<"\n";
    return 0;
}

//Time Complexity: O(n)