#include <bits/stdc++.h>
using namespace std;

bool isLongPressedName(string name, string typed) 
{
        int i=0, j=0;
        int n=name.size(),m=typed.size();
	while(i<n && j<m)
    {
		int ct=0, cn=0;
		while(typed[j+1]==typed[j]){
			ct++;
			j++;
		}
		while(name[i+1]==name[i]){
			cn++;
			i++;
		}
		if(typed[j]!=name[i] || cn>ct) 
            return false;
		i++;
		j++;
	}
	if(i==name.size() && j==typed.size() && name[i]==typed[j]) 
           return true;
	return false;   
}
int main()
{
    string name = "alex", typed = "aaleex";
	if(isLongPressedName(name,typed))
	   cout<<"true";
	else
	  cout<<"false";
	return 0;
	
}

