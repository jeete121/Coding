#include <bits/stdc++.h>
using namespace std;


//function to count all good pairs
int countGoodTriplets(vector<int>& arr, int a, int b, int c) 
{
       int cnt=0;
        int n=arr.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                if(abs(arr[i]-arr[j])<=a)
                {
                for(int k=j+1;k<n;k++)
                {
                    if(abs(arr[j]-arr[k])<=b&&abs(arr[i]-arr[k])<=c)
                          cnt++;
                }
                }
            }
        }
        return cnt;
}
int main()
{
  vector<int> arr ={3,0,1,1,9,7};
  int a = 7, b = 2, c = 3;
  cout<<countGoodTriplets(arr,a,b,c);
  return 0;
}

