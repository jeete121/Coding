#include <bits/stdc++.h>
using namespace std;


//function to find the kth missing
//positive number
int findKthPositive(vector<int>& arr, int k) 
{
    int start=1;
    int ans=0;
    for(int i=0;i<arr.size();i++)
       { 
            int left=arr[i]-start;
            int p=k;
            k=k-left;
           if(k<=0)
           {
             for(int j=start;j<arr[i];j++)
             {
                 p--;
                 if(p==0)
                 {
                     ans=j;
                     break;
                 }
             }    
           }
          start=arr[i]+1;
       }
        if(ans==0)
        {
            ans=k+arr[arr.size()-1];
        }
        return ans;
}
int main()
{
     vector<int> arr ={2,3,4,7,11};
     int k = 5;
     cout<<findKthPositive(arr,k);
     return 0;
}
