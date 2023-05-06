#include <bits/stdc++.h>
using namespace std;

vector<int> sumZero(int n) 
{
   vector<int> res;
   int sum=0;
     for(int i=1;i<=n-1;i++) 
       {
          res.push_back(-i);
         sum+=i;
      }
        res.push_back(sum);
     return res;
}
int main()
{
    int n=5;
    vector<int> arr=sumZero(n);
    for(int i=0;i<arr.size();i++)
       cout<<arr[i]<<" ";
    return 0;
}

