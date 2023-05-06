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

//function to remove the vowels 
//from the string
void  removeVowels(string &str)
{
    int index=0;
    for(int i=0;i<str.size();i++)
      {
          if(!isVowel(str[i]))
             str[index++]=str[i];
      }
    str.resize(index);
}
int main()
{
      string str="Hello World";
      removeVowels(str);
      cout<<str<<"\n";
      return 0;
}