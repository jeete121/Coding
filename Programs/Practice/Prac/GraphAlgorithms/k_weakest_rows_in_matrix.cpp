#include <bits/stdc++.h>
using namespace std;



int last(vector<int> &arr,int low,int high)
{
      if(high>=low)
      {
          int mid=low+(high-low)/2;
        if (( mid== 0||arr[mid-1]==0)&& arr[mid]==1)  
            return mid;
          if(arr[mid]==0)
              return last(arr,mid+1,high);
          else
              return last(arr,low,mid-1);
      }
     return -1;
}

//function to find the kweakest rows 
//in the matrix
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector< pair<int,int > > v;
    int C=mat[0].size(),index;
   for(int i=0;i<mat.size();i++)
      {
       sort(mat[i].begin(),mat[i].end());

       //find the last index where 1 occurs
       index=last(mat[i],0,C-1);
        if(index!=-1)
            v.push_back(make_pair(C-index,i));
        else
           v.push_back(make_pair(0,i));
      }
     sort(v.begin(),v.end());
     vector<int> res;
     for(int i=0;i<k;i++)
          res.push_back(v[i].second);
     return res;
}
int main()
{
  vector<vector<int>> mat={{1,1,0,0,0},
                         {1,1,1,1,0},
                         {1,0,0,0,0},
                         {1,1,0,0,0},
                         {1,1,1,1,1}};
  int k=3;
  vector<int> kweak=kWeakestRows(mat,k);
  for(int i=0;i<k;i++)
     cout<<kweak[i]<<" ";
  return 0;
}

