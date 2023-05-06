#include <bits/stdc++.h>
using namespace std;

//function to find the maximum
//product of two elements
int maximumProductTwo(int arr[],int n)
{

    //vaiable to store the max1 and max2
    int max1=arr[0],max2=arr[1];

    //variabe to store the min1 and min2
    int min1=arr[0],min2=arr[1];
    if(max1<max2)
       swap(max1,max2);
    if(min1>min2)
       swap(min1,min2);

    //iterate till the end of array
    //and find the minimum 2 elements
    //and maximum 2 elements
    for(int i=2;i<n;i++)
     {
         if(arr[i]>max1)
           {
               max2=max(max2,max2);
               max1=arr[i];
           }
         else if(arr[i]>max2)
           {
               max2=arr[i];
           }
         if(arr[i]<min1)
           {
               min2=min(min2,min1);
               min1=arr[i];
           }
          else if(arr[i]<min2)
            {
                min2=arr[i];
            }
     }
    return max(max1*max2,min1*min2);
}
int main()
{

    //input array 
    int arr[]={3,4,-4,-7,5};

    //size of array 
    //size of array must be  greater than or 
    //equal to 2
    int n=sizeof(arr)/sizeof(arr[0]);
    int maximum=maximumProductTwo(arr,n);
    cout<<maximum<<"\n";
}