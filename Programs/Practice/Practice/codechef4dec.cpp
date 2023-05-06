#include <bits/stdc++.h>
using namespace std;
int add(string A,string B)
{
    int cnt=0;
    string s="0";
  while(B.compare(s)>0)
  {
      string U=A^B;
      string V=A&B;
      A=U;
      B=V*2;
      cnt++;
  }
  return cnt;
}
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
     string A,B;
     cin>>A>>B;
     cout<<add(A,B)<<"\n";
 }
}
