#include <bits/stdc++.h>
using namespace std;

string interpret(string s) 
{
    int n=s.size();
    int i=0;
    string ans="";

    //iterate till the end of 
    //length of string
    while(i<n)
    {
        if(s[i]=='G')
        {
                ans+=s[i];
                i+=1;
         }
         //if () then ans =ans+"o"
        else if(s[i]=='('&&s[i+1]==')')
         {
                ans+="o"; 
               i+=2;
         }
        //else ans=ans+"al";
       else
        {
                ans+="al";
                i+=4;
        }
        
     }    
        return ans;
}
int main()
{
     string str="G()(al)";
     string goal=interpret(str);
     cout<<goal<<"\n";
     return 0;
}
