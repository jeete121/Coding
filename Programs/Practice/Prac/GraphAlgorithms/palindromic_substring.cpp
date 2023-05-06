#include <bits/stdc++.h>
using namespace std;


//function to check if 
//string is palindrome or not
bool ispalindrome(string &s)
{
        int n=s.size();
        int flag=0;
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
              return true;
        return false;
}
int countSubstrings(string s) 
{
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            string str="";
            for(int j=i;j<s.size();j++)
            {
                str+=s[j];
                if(ispalindrome(str))
                      cnt++;
            }
        }
        return cnt;
}

int main()
{
    string str="abc";
    cout<<countSubstrings(str);
    return 0;
}