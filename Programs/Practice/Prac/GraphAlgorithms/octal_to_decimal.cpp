#include <bits/stdc++.h>
using namespace std;
//Function to convert from
//octal to decimal
int  octalToDecimal(int octal)
{
   int decimal=0;
   int i=0;
  while(octal>0)
    { 
      int mod=octal%10;
      decimal=decimal+mod*pow(8,i);
      i++;
      octal=octal/10;
    }
    return decimal;
}
int main()
{
    int octal=635;
    int  decimal=octalToDecimal(octal);
    cout<<"Decimal is ";
    cout<<decimal<<"\n";
    return 0;
}