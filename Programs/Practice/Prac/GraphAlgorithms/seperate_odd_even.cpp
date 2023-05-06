#include <bits/stdc++.h>
using namespace std;

//function to find even number
vector<int>  evenFind(int arr[],int n) 
{
    vector<int> even;
     for (int i = 0; i <n; i++) {
            if (arr[i] % 2 == 0) {
                even.push_back(arr[i]);
            }
        }
   return even;
}

//function to find odd number
vector<int> oddFind(int arr[],int n) 
 {
     vector<int> odd;
     for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
               odd.push_back(arr[i]);
            }
        }
       return odd;
}

int main()
{
   int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   int n=sizeof(arr)/sizeof(arr[0]);
   vector<int> odd= oddFind(arr,n);
   vector<int> even = evenFind(arr,n);
   cout<<"Odd : ";
   for(int i=0;i<odd.size();i++)
       cout<<odd[i]<<" ";
   cout<<"Even : ";
   for(int i=0;i<even.size();i++)
      cout<<even[i]<<" ";
   return 0;
}
