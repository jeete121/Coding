#include <bits/stdc++.h>
using namespace std;

//function to reverse a string
string reverseString(string str)
{
    //character stack to hold the
    //the current current characterss
    stack<char> st;
    for(int i=0;i<str.size();i++)
       st.push(str[i]);
    string reverse="";

    //iterate till the stack is 
    //not empty
    while(!st.empty())
      {
          reverse+=st.top();
          st.pop();
      }
    return reverse;
}
int main()
{
    string str = "Hello Word";
    string reverse=reverseString(str);
    cout<<reverse;
    return 0;
}