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
//function to convert from
//decimal to binary
string decimalToBinary(int decimal)
{
    string binary="";
    while(decimal>0)
     {
         if(decimal%2==0)
            binary='0'+binary;
         else
           binary='1'+binary;
        decimal=decimal/2;
     }
     return binary;
}
int main()
{
    string hexadecimal="5F";
    int decimal=hexadecimalToDecimal(hexadecimal);
    string binary=decimalToBinary(decimal);
    cout<<"Binary is ";
    cout<<binary<<"\n";
    return 0;
}