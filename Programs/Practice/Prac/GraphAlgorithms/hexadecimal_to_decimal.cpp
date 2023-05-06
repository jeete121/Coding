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
int main()
{
    string hexadecimal="4AB";
    int decimal=hexadecimalToDecimal(hexadecimal);
    cout<<"Decimal is ";
    cout<<decimal<<"\n";
    return 0;
}