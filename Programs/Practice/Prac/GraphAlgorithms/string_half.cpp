#include <bits/stdc++.h>
using namespace std;

//function to check the
//character is vowel or not
bool isVowel(char ch)
{
  if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
             return true;
   if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
             return true;
     return false;
}

//function to check the halves are alike
//or not
bool halvesAreAlike(string s) 
{
        int n=s.size();
        int half=0;
        for(int i=0;i<s.size()/2;i++)
        {
            if(isVowel(s[i]))
                  half++;
        }
      for(int i=s.size()/2;i<s.size();i++)
      {
          if(isVowel(s[i]))
                half--;
      }
      if(half==0)
            return true;
      return false;
    }
int main()
{
   //string length must be
   //even
    string str="book";
    if(halvesAreAlike(str))
      cout<<"Alike\n";
    else
     cout<<"Not alike\n";
  return 0;
}
