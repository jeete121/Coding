#include <bits/stdc++.h>
using namespace std;


//function to find repeated number
int repeatedNTimes(int arr[],int n)
{
    map<int,int> map;
        // iterate till end of element
    for (int i = 0; i < n; i++) {
            // if all-read then return the elemenet
            if (map.find(arr[i])!=map.end()) 
            {
                return arr[i];
            } else {
               map[arr[i]]++;
            }
     }
        return 0;

}

int main()
{
   int arr[] = { 1, 2, 3, 3 };
   int n=sizeof(arr)/sizeof(arr[0]);
   cout<<repeatedNTimes(arr,n)<<"\n";
   return 0;
}
