#include <bits/stdc++.h>
using namespace std;

//function to decomrees
//the run length encodin
// pair(a,b) means b occurs a times
vector<int> decompressRLElist(int arr[],int n) 
{
    vector<int> res;
     for(int i=0;i<n;i+=2)
         {
             while(arr[i]--)
             {
                 res.push_back(arr[i+1]);
             }
        }
        return res;
}
int main()
{

    //input array must be of even length
    int arr[]={1,2,3,4};
    int  n=sizeof(arr)/sizeof(arr[0]);
    vector<int> newArr=decompressRLElist(arr,n);
    for(int i=0;i<newArr.size();i++)
       cout<<newArr[i]<<" ";
    return 0;
}
  
