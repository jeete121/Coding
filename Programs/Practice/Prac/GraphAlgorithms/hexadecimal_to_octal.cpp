#include <bits/stdc++.h>
using namespace std;
//function to convert from hexadecimal to
//decimal
int hexadecimalToDecimal(string hexadecimal)
{
  int decimal=0;
  int n=hexadecimal.size();
  for(int i=0;i<n;i++)
   {
       //if hexadecimal[i]>='0'&&hexadecimal[i]<='9'
       if(hexadecimal[i]>='0'&&hexadecimal[i]<='9')
          {
              int num=hexadecimal[i]-'0';
              decimal=decimal+pow(16,n-i-1)*num;
          }
        //if hexadecimal[i]>='A'&&hexadecimal[i]<='F'
        else
         {
             int num=hexadecimal[i]-'A'+10;
             decimal=decimal+pow(16,n-1-i)*num;
         }
   }
   return decimal;
}
//function to convert from hexadecimal to
//octal
string hexadecimalToOctal(string hexadecimal)
{
    int decimal=hexadecimalToDecimal(hexadecimal);
    string octal="";
    while(decimal>0)
     {
        octal=to_string(decimal%8)+octal;
        decimal=decimal/8;   
     }
     return octal;
}
int main()
{
  string hexadecimal="5F";
  string octal=hexadecimalToOctal(hexadecimal);
  cout<<"Octal is ";
  cout<<octal<<"\n";
  return 0;
}