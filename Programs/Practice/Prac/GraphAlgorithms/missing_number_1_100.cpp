#include <bits/stdc++.h>
using namespace std;

// find maximum element
int maxElement(int arr[],int n)
{
    int max = arr[0];
    for (int i = 1; i <n; i++) 
      {
            if (arr[i] > max)
                max = arr[i];
     }
        return max;
}
    // find missing element
vector<int> findMissing(int arr[],int n) 
{

    vector<int> missing;
    int max = maxElement(arr,n);
    // if no missing
    if (max ==n)
     return missing;
   // assume all are missing
    bool miss[max+1];
    memset(miss,false,sizeof(miss));
        // iterate till end of arr
    for (int i = 0; i <n; i++) {
            // update non-missing element
            miss[arr[i]] = true;

        }
    int index = 0;
        for (int i = 1; i <=max; i++) {
            if (!miss[i]) {
            missing.push_back(i);
            }
        }

        return missing;
}
int main()
{
  int arr[] = { 1, 2, 3, 8, 12 };
  int n=sizeof(arr)/sizeof(arr[0]);
  vector<int> missing = findMissing(arr,n);
  for(int i=0;i<missing.size();i++)
     cout<<missing[i]<<" ";
  return 0;
}

