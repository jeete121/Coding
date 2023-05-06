#include <bits/stdc++.h>
using namespace std;
//Function to convert decimal to 
//octal
string decimalToOctal(int num)
{
    string octal="";
    while(num>0)
      {
          octal+=to_string(num%8);
          num=num/8;
      }
    reverse(octal.begin(),octal.end());
    return octal;
}
int main()
{
    int num=25;
    string octal=decimalToOctal(num);
    cout<<"Octal is ";
    cout<<octal<<"\n";
    return 0;
}