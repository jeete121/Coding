#include <bits/stdc++.h>
using namespace std;


//function to sort the array according
//to the second array
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
{
        map<int,int> mp;
        int n=arr1.size();
        for(int i=0;i<n;i++)
              mp[arr1[i]]++;
        vector<int> v;
        int m=arr2.size();
       for(int i=0;i<m;i++)
       {
           int x=mp[arr2[i]];
           while(x--)
                  v.push_back(arr2[i]);
           mp[arr2[i]]=0;
       }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int x=it->second;
            while(x--)
                  v.push_back(it->first);
        }
        return v;
}
int main()
{
    vector<int> arr1 ={2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> result=relativeSortArray(arr1,arr2);
    for(int i=0;i<result.size();i++)
       cout<<result[i]<<" ";
   return 0;
}
