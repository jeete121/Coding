#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& citations) 
{
     int n=citations.size();
      int low=0,high=n;
      while(low<high)
      {
          int mid=low+(high-low)/2;
          if(citations[mid]<n-mid)
                 low=mid+1;
          else
              high=mid;
      }
        return n-low;
}

int main()
{
    vector<int>  citations ={0,1,3,5,6};
    cout<<hIndex(citations);
    return 0;
}