#include <bits/stdc++.h>
using namespace std;

//function to find the first 
//non repeating character
char firstNonRepeating(string str)
{
    set<char> st;
    char ans='#';
    for(int i=str.size()-1;i>=0;i--)
      {
          if(str[i]!=' ')
            {
                if(st.find(str[i])==st.end())
                  {
                      ans=str[i];
                      st.insert(str[i]);
                  }
            }
      }
    return ans;
}
int main()
{

    //input string must contain one 
    //character which occur ones
    string str="Hi Hello World";
    char first=firstNonRepeating(str);
    cout<<"First Non Repeating is ";
    cout<<first<<"\n";
    return 0;
}