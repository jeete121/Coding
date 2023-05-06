#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) 
{
     string x="";
     for(int i=1;i<=n;i++)
        {
            x+=to_string(i);
        }
      k=k-1;
        while(k)
        {
            bool flag=next_permutation(x.begin(),x.end());
            k--;
        }
    return x;
}
int main()
{
 int n=3,k=3;
 cout<<getPermutation(n,k);
 return 0;
}

