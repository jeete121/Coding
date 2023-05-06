#include <bits/stdc++.h>
using namespace std;

//function to find the maximum product
//of three numbers in the array
//array must contains at least 4 elements
int maximumProduct(int arr[],int n)
{
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,max4=INT_MIN;
   
   //find the maximum four elements
    for(int i=0;i<n;i++)
      {

          //update max1,max2, man3 and max4
          if(arr[i]>max1)
            {
                max4=max(max4,max3);
                max3=max(max2,max3);
                max2=max(max2,max1);
                max1=arr[i];
            }

          //update max2,max3 and max4
          else if(arr[i]>max2)
           {
               max4=max(max4,max3);
               max3=max(max2,max3);
               max2=arr[i];
           }

        //update max3 and max4
         else if(arr[i]>max3)
            {
                max4=max(max4,max3);
                max3=arr[i];
            }
         
         //update max4
         else if(arr[i]>max4)
            max4=arr[i];
      }
    int min1=INT_MAX,min2=INT_MAX,min3=INT_MAX,min4=INT_MAX;

    //find the minimum four elements
    for(int i=0;i<n;i++)
      {

          //update min1 ,min2,min3 and min4
       if(arr[i]<min1)
         {
             min4=min(min3,min4);
             min3=min(min2,min3);
             min2=min(min1,min2);
             min1=arr[i];
         }

         //update min2,min3 and min4
        else if(arr[i]<min2)
           {
               min4=min(min4,min3);
               min3=min(min2,min3);
               min2=arr[i];
           }
        //update min3 and min4
        else if(arr[i]<min3)
         {
             min4=min(min4,min3);
             min3=arr[i];
         }
         //update min4
         else if(arr[i]<min4)
               min4=arr[i];
      }
     //case 1: maximum=max1*max2*max3*max4
     //case 2: maximum =min1*min2*min3*min4
     //case 3: maximum=min1*min2*max1*max2
     int case1=max1*max2*max3*max4;
     int case2=min1*min2*min3*min4;
     int case3=min1*min2*max1*max2;
    return max(case1,max(case2,case3));
}

int main()
{
    //array must contains 4 elements
     int arr[]={3,1,4,-5,-6,8};
     int n=sizeof(arr)/sizeof(arr[0]);

     //i.e (-5)*(-6)*8*4
     int maximum=maximumProduct(arr,n);
     cout<<maximum<<"\n";
     return 0;
}

//Time Complexity: O(n)
