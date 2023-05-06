#include <bits/stdc++.h>
using namespace std;

//function to arrange coins
int arrangeCoins(int n) 
{
   int i=1;
    int cnt=0;
   while(i<=n)
       {
           cnt++;
           n=n-i;
           i++;
       }
  return cnt;
}
int main()
{
  int n=5;
  cout<<arrangeCoins(n);
  cout<<"\n";
  return 0;
}