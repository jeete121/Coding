#include <bits/stdc++.h>
using namespace std;

//function to check for
//palindrome string
bool isPalindrome(string s)
{
    int low=0,high=s.size()-1;
    while(low<high)
        {
            if(s[low]!=s[high])
                  return false;
            low++;
            high--;
        }
   return true;
}
string breakPalindrome(string s) 
{
        int i=0;
        int n=s.size();
        if(n==1)
              return "";
        while(i<n&&s[i]=='a')
              i++;
       if(i==n)
             s[n-1]='b';
        else
        {
            while(true)   
            {
            char temp=s[i];
            s[i]='a';
            if(isPalindrome(s))
            {
                s[i]=temp;
                i++;
                if(i==n)
                {
                    s[i-1]='b';
                    break;
                }
                 
            }
             else
                  break;
            }
        }
        return s;
}
int main()
{
    string palindrome = "abccba";
    cout<<breakPalindrome(palindrome);
    return 0;
}

