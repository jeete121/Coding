#include <bits/stdc++.h>
#define INT_SIZE sizeof(int)*8
using namespace std;
int circularshift(unsigned n,int k,bool leftshift)
{
    if(leftshift)
      return (n<<k)|(n>>(INT_SIZE-k));
    return (n>>k)|(n<<(INT_SIZE-k));
}
int main()
{
    unsigned n;
    int k;
    cout<<"Enter a number:\n";
    cin>>n;
    cout<<"Enter shift positions:\n";
    cin>>k;
    cout<<"No Shift "<<bitset<32>(n)<<"\n";
    cout<<"Left Shift "<<bitset<32>(circularshift(n,k,1))<<"\n";
    cout<<"Right Shift "<<bitset<32>(circularshift(n,k,0));
   return 0;
}