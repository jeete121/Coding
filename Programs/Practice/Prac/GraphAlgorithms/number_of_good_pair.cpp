#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(int nums[],int n) 
{
    map<int,int> fMap;
    int ngp = 0;
    for (int i = 0; i <n; i++) 
    {
            fMap[nums[i]]++;
     }

    for(auto it=fMap.begin();it!=fMap.end();it++)
       {

           int p=it->second;
           ngp+=p*(p-1)/2;
       }
    return ngp;
}

int main()
{
    int nums[] = { 1, 2, 3, 1, 1, 3 };
    int n=sizeof(nums)/sizeof(nums[0]);
    int good_pair = numIdenticalPairs(nums,n);
    cout<<good_pair;
    return 0;
}
