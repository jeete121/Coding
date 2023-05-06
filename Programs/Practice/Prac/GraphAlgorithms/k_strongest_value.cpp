#include <bits/stdc++.h>
using namespace std;

//function to find the median of the
//array
int getMedian(vector<int> arr)
{
        sort(arr.begin(),arr.end());
        int n=arr.size();
        return arr[(n-1)/2];
}

//comparator
static bool cmp(pair<int,int>a,pair<int,int> b)
{
      if(a.second==b.second)
             return a.first>b.first;
       return a.second>b.second;
}

//function to find the k strongest value
//in the array
vector<int> getStrongest(vector<int>& arr, int k) 
{
     int  median=getMedian(arr);
        vector<pair<int,int>> v;
      for(int i=0;i<arr.size();i++)
      {
          v.push_back({arr[i],abs(arr[i]-median)});
      }
        sort(v.begin(),v.end(),cmp);
        arr.clear();
        for(int i=0;i<k;i++)
              arr.push_back(v[i].first);
        return arr;
} 

int main()
{
    vector<int>arr ={1,2,3,4,5};
    int k = 2;
    vector<int> newArr=getStrongest(arr,k);
    for(int i=0;i<newArr.size();i++)
      cout<<newArr[i]<<" ";
    return 0;
}
