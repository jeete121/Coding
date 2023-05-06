#include <bits/stdc++.h>
using namespace std;
//Function to convert from 
//decimal to hexadecimal
string decimalTohexaDecimal(int num)
{
    string hexaDecimal="";
    while(num>0)
      {
          int mod=num%16;
          if(mod<=9)
             hexaDecimal+=to_string(mod);
          else
            hexaDecimal+='A'+mod-10;
           num=num/16;
      }
      reverse(hexaDecimal.begin(),hexaDecimal.end());

    return hexaDecimal;
}
int main()
{
    int num=168;
    string hexaDecimal=decimalTohexaDecimal(num);
    cout<<"Hexadecimal is ";
    cout<<hexaDecimal<<"\n";
    return 0;
}