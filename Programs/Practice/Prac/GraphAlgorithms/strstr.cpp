#include <bits/stdc++.h>
using namespace std;

//function to find the pattern string
//into the text string
int strStr(string text, string pattern)
{
        int n=text.size(),m=pattern.size();
        for(int i=0;i<=n-m;i++)
        {
            int j;
            for(j=0;j<m;j++)
                   if(text[i+j]!=pattern[j])
                         break;
            if(j==m)
                  return i;
        }
        return -1;
}   
int main()
{
    string text="hello";
    string pattern="ll";
    int index=strStr(text,pattern);
    if(index==-1)
      cout<<"Not found";
    else
     cout<<"Found at "<<index<<"\n";
  
   return 0;
    
}