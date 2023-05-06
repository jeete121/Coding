#include <bits/stdc++.h>
using namespace std;
int prec(char c)
{
  if(c=='^')
     return 3;
  else if(c=='/'||c=='*')
     return 2;
   else if(c=='+'||c=='-')
     return 1; 
    return -1;

}
int main()
{
  int t,n;
  cin>>t;
  while(t--)
   {
     cin>>n;
     string s;
     cin>>s;
     stack<char> st;
     string ans="";
     for(int i=0;i<n;i++)
       {
         if(s[i]>='A'&&s[i]<='Z')
             ans+=s[i];
         else if(s[i]=='(')
            st.push(s[i]);
         else if(s[i]==')')
           {
             while(!st.empty()&&st.top()!='(')
               {
                 ans+=st.top();
                 st.pop();
               }
              if(st.top()=='(')
                 st.pop();
           }
          else
          {
             while(!st.empty()&&prec(s[i])<=prec(st.top()))
             {
                ans+=st.top();
                st.pop();
              }
              st.push(s[i]);
          }
          
       }
       while(!st.empty())
          {
            ans+=st.top();
            st.pop();
          }
      cout<<ans<<"\n";
   }
  return 0;
}