#include <bits/stdc++.h>
using namespace std;


//function to reverse each words in the string
string reverseWords(string s)
{
       int n=s.size();
        if(n==0)
              return "";
       int i=0,j=n-1;

       //if their are spaces in
       //start of string
        while(i<n&&s[i]==' ')
              i++;
        
        //if their are spaces in the end of string
        while(j>0&&s[j]==' ')
              j--;
        string res="";

        //now iterate in remaining string
        while(i<=j)
         {
              string x="";
           while(i<=j&&s[i]!=' ')
           {
               x+=s[i];
               i++;
           }

           //reveres the current word
            reverse(x.begin(),x.end());

           //add into the result
            res+=x;
            if(i<j)
               res+=" ";
            while(i<=j&&s[i]==' ')
                  i++;
         }
        return res;
}
int main()
{
    string str="Hello world";
    cout<<reverseWords(str);
    return 0;
}

