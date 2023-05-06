#include <bits/stdc++.h>
using namespace std;

//function to count the 
//number of set bits
int countsetbits(int a)
{
   int cnt=0;
    while(a)
    {
        a=a&(a-1);
        cnt++;
   }
  return cnt;
}

//comparator for sort
bool comp(int i, int j) 
{
    int cnt1=countsetbits(i);
    int cnt2=countsetbits(j);
    if(cnt1!=cnt2)
      return cnt1<cnt2;
    else 
       return   i<j;
}

//function to sort the array
//with the count of set bits
vector<int> sortByBits(vector<int> &arr)
{
       sort(arr.begin(), arr.end(), comp);
        return arr;
}
int main()
{
   vector<int> arr ={0,1,2,3,4,5,6,7,8};
   vector<int> nums=sortByBits(arr);
   for(int i=0;i<nums.size();i++)
      cout<<nums[i]<<" ";
  return 0;
}

