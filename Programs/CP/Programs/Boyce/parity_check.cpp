#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int n=s.size(),cnt=0;
  for(int i=0;i<n;i++)
    {
	  if(s[i]=='1')
	     cnt++;
	}	
  if(cnt&1)
     cout<<"Odd Parity\n";
  else
    cout<<"Even Parity\n";
}

