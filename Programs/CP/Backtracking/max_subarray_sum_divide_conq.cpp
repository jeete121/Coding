#include <bits/stdc++.h>
using namespace std;
vector<int> find_max_sum_crossing(int arr[],int low,int mid,int high)
{
  int left_sum=INT_MIN;
  int sum=0,max_left;
  for(int i=mid;i>=low;i--)
  {
     sum=sum+arr[i];
     if(sum>left_sum)
     {
         left_sum=sum;
         max_left=i;
     }
  }

  int right_sum=INT_MIN;
  int sum=0,max_right;
  for(int i=mid+1;i<high;i++)
  {
     sum=sum+arr[i];
     if(sum>right_sum)
     {
         right_sum=sum;
         max_right=i;
     }
  }
  vector<int > v;
  v.push_back(max_left);
  v.push_back(max_left);
  v.push_back(left_sum+right_sum);
  return v;
}
vector <int> find_max_subarray(int arr[],int low,int high)
{
  if(low==high)
  {
  vector<int> v;
  v.push_back(low);
  v.push_back(high);
  v.push_back(arr[low]);
  return v;
  }
}
int main()
{
    int
}
