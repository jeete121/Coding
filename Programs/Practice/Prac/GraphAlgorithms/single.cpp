#include <bits/stdc++.h>
using namespace std;
//function to find the single element
//in the array ,array contains all element twice
//except the one element
int singleElement(int arr[],int n)
{
    //map to hold the count of 
    //all the number
    map<int,int> mp;
    for(int i=0;i<n;i++)
      {
        //increment the count of
        //current element
          mp[arr[i]]++;
      }
    
    //initialize the single element as arr[0]
    int single=arr[0];
   
   //iterate the map
    for(auto it=mp.begin();it!=mp.end();it++)
       {
           //if frequency is 1
           if(it->second==1)
             {
                 //store the single as the current 
                 //element
                 single=it->first;
                 break;
             }
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