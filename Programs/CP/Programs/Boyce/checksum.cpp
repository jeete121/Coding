#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	string res="";
	cin>>s1;
	cin>>s2;
	//set<int> st;
	int n=s1.size(),carry=0;
		reverse(s1.begin(),s1.end());
			reverse(s2.begin(),s2.end());
	for(int i=0;i<n;i++)
	 {
		 int z=(s1[i]-'0'+s2[i]-'0'+carry)%2;
		 carry=(s1[i]-'0'+s2[i]-'0'+carry)/2;
		 ostringstream str1;
		 str1<<z;
		 string geek=str1.str();
		 res+=geek;
		

     }
     for(int i=0;i<n;i++)
        if(res[i]=='0')
           res[i]='1';
        else
           res[i]='0';
	 reverse(res.begin(),res.end());
	 cout<<res<<"\n";
}
