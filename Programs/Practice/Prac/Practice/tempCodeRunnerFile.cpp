#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	int cnt=0;
    while(n--)
	 {
		 int x;
		 cin>>x;
		 if(x==1)
		    cnt++;
	 }
	if(cnt==0)
	   cout<<"EASY\n";
	else
	   cout<<"HARD\n";
	
	return 0;
}