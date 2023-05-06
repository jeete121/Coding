#include <bits/stdc++.h>
using namespace std;

//function to find the single
//element of the array
//array contains all elements twice
//execpt the one element which occur 
//one time
int singleElement(int arr[],int n)
{
    int single=arr[0];

    //iterate for all the 
    //element of the array
    for(int i=1;i<n;i++)
      {
          //update single element as 
          //single =single^arr[i]
          //xor of 2 same number beomes 0
          single=single^arr[i];
      }

    //return the single element
    return single;
}
int main()
{
    int arr[]={2,2,1,3,1};

    //find the length of array
    int n=sizeof(arr)/sizeof(arr[0]);
    int single=singleElement(arr,n);
    cout<<"Single element is ";
    cout<<single<<"\n";
    return 0;
}