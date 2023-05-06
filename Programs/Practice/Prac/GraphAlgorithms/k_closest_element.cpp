#include <bits/stdc++.h>
using namespace std;



int findK(vector<int> &arr,int k)
{
        int low=0,high=arr.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==k)
                  return mid;
            else  if(arr[mid]>k)
                    high=mid-1;
            else
                low=mid+1;
        }
        return -1;
}


vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
          vector<int> res;
        int n=arr.size();
            for(int i=0;i<k;i++)
            {
                res.push_back(arr[i]);
            }
            for(int i=k;i<n;i++)
            {
                if(abs(res[0]-x)>abs(arr[i]-x))
                {
                    res.erase(res.begin());
                    res.push_back(arr[i]);
                }                       
            }
        sort(res.begin(),res.end());
        return res;
}

int main()
{
    vector<int> arr ={1,2,3,4,5};
    int k = 4, x = 3;
    vector<int> closest=findClosestElements(arr,k,x);
    for(int i=0;i<closest.size();i++)
       cout<<closest[i]<<" ";
    return 0;
}