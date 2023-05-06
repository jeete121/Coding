#include <bits/stdc++.h>
using namespace std;


//sort the array by parity
vector<int> sortArrayByParity(vector<int>& A) 
{
    vector<int> res;

    //for even numbers
    for(int i=0;i<A.size();i++)
        {
          if(A[i]%2==0)
           {

             res.push_back(A[i]);
           }
        }
    //for odd numbers
    for(int i=0;i<A.size();i++)
        {
            if(A[i]&1)
              {
                  res.push_back(A[i]);
              }
        }
    return res;
}
int main()
{
   vector<int> arr={3,1,2,4};
   vector<int> newArray=sortArrayByParity(arr);
   for(int i=0;i<newArray.size();i++)
      cout<<newArray[i]<<" ";
   return 0;
}

