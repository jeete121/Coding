#include <bits/stdc++.h>
using namespace std;


int P[10100];
string convert(string s)
{
        string res="";
        res+="@";
        for(int i=0;i<s.size();i++)
               res+="#"+s.substr(i,1);
         res+="#$";
        return res;
}

//function to find the langest palinndromic substrig

string longestPalindrome(string s) 
{

        //convert the string
        string str=convert(s);
        int c=0,r=0;

        //now itearte  till the length
        //of new string
        for(int i=1;i<str.size()-1;i++)
        {
            int mirror=c-(i-c);
            if(r>i)
                  P[i]=min(r-i,P[mirror]);
            while(str[i+1+P[i]]==str[i-1-P[i]])
                   P[i]++;
            if(i+P[i]>r)
            {
                r=i+P[i];
                c=i;
            }
        }
        int len=0,center=0;
        for(int i=0;i<str.size()-1;i++)
        {
            if(P[i]>len)
            {
                len=P[i];
                center=i;
            }
        }
        return s.substr((center-1-len)/2,len);
}
int main()
{
   string str = "babad";
   cout<<longestPalindrome(str);
   return 0;
}
