#include <bits/stdc++.h>
using namespace std;

//function to reverse the string
string stringReverse(string str)
{

    //vaiable to hold the final
    //answer
    string rev="";

    //iterate till the length
    //of string
    for(int i=0;i<str.size();i++)
      {
          //rev=str[i]+rev
          //append in reverse order
          rev=str[i]+rev;

      }
    return rev;
}
int main()
{
    string str="Hello Word";
    string rev=stringReverse(str);
    cout<<"Reverse string is\n";
    cout<<rev<<"\n";
    return 0;
}