#include <bits/stdc++.h>
using namespace std;
//function to calculate freq of array element
map<int, int> findFrequency(int arr[],int n) 
{
       map<int,int> freq;
      // iterate till end of loop
        for (int i = 0; i <n; i++) {
            // add and update frequency
           freq[arr[i]]++;
        }
        return freq;
}
int main()
{
    int arr[] = { 1, 3, 5, 1, 2, 7, 2, 1 };
    int n=sizeof(arr)/sizeof(arr[0]);
    map<int, int> freq = findFrequency(arr,n);
    for(auto it=freq.begin();it!=freq.end();it++)
       cout<<"Value "<<it->first<<" Freq "<<it->second<<"\n";
    return 0;
}

