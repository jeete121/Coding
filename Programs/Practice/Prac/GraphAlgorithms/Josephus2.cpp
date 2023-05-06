/*
Modeling a O(klogn) solution
If k is a lot smaller than n, then we can delete multiple numbers 
(⌊nk⌋) in one run without looping over.Afterwards we have n−⌊nk⌋ numbers 
left, and we start with the (⌊nk⌋⋅n)-th number. So we have to shift by 
that many. We can notice that ⌊nk⌋⋅n is simply nmodk. And since we removed
every k-th number,we have to add the number of numbers that we removed 
before the result index
*/
/*
Jn,2=1+2(n−2^⌊log2n⌋)
*/
#include <bits/stdc++.h>
using namespace std;
int josephus(int n,int k)
{
    if(n==1)
      return 0;
    if(k==1)
      return n-1;
    if(k>n)
      return (josephus(n-1,k)+k)%n;
    int cnt=n/k;
    int res=josephus(n-cnt,k);
    res-=n%k;
    if(res<0)
       res+=n;
    else
      res+=res/(k-1);
    return res;
    
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<josephus(n,k)<<"\n";
    return  0;
}