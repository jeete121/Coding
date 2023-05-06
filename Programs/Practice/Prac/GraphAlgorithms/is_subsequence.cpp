#include <bits/stdc++.h>
using namespace std;


//function to check if string
// is subsequence of other string
bool isSubsequence(string s, string t) 
{
        int n=s.size(),m=t.size();
        if(m<n)
              return false;
        int i=0,j=0;
        while(i<n&&j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        if(i==n)
              return true;
        return false;
        
}
int main()
{
  string s="abc";
  string t="ahbgdc";
  if(isSubsequence(s,t))
    cout<<"true\n";
  else
    cout<<"false\n";
  return 0;
  
}
