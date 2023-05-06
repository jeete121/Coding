#include <bits/stdc++.h>
using namespace std;
string xor1(string s1,string s2)
{
	string res="";
	int n=s1.size();
  for(int i=0;i<n;i++)
     {
	   if((s1[i]=='1'&&s2[i]=='1')||(s1[i]=='0'&&s2[i]=='0'))
	      res+='0';
	   else
	      res+='1';	 
     }	
    return res;
}
int main()
{
 string s1,s2;
 cin>>s1>>s2;
 string str="";
 string res="";
 int n1,n2=s2.size();
 for(int i=0;i<n2-1;i++)
    str+='0';
  s1.append(str);
  n1=s1.size();
  string p="";
  for(int i=0;i<n2;i++)
      p+=s1[i];
   for(int i=n2;i<n1;i++)
     {
	    res=xor1(p,s2);
	    int j=0,cnt=0;
	   while(true)
	       {
			if(res[j]=='0')
			 {
				 cnt++;
			 j++;}
			 else
			   break;   
		   }
		   string x="";
		   int z=res.size();
		  for(int k=j;k<z;k++)
		     {
			   x+=res[k]; 
			 }
		  while(cnt)
		    {
		     if(i<n1)
			  x+=s1[i];
			  cnt--;	
			}
			p=x;
			res=x;
	 }
	 cout<<res<<"\n";
  return 0;
}
