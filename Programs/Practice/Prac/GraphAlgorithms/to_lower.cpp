#include <bits/stdc++.h>
using namespace std;

//function to convert the
//upper case letters into 
//lower case
string tolowerCase(string str)
{
    for(int i=0;i<str.size();i++)
      {
          if(str[i]>='A'&&str[i]<='Z')
             str[i]=str[i]+32;
      }
    return str;
}
int main()
{
    string str="Hello Java";
    string lower=tolowerCase(str);
    cout<<lower<<"\n";
    return 0;
}