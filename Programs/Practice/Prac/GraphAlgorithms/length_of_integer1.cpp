#include <bits/stdc++.h>
using namespace std;
//function to find the legth
//of given number
int lengthNumber(int num)
{
  //length of number is log10(n)
   int length=log10(num)+1;
   //return the length of number
   return length;
}
int main()
{
    int num=123;
    int lenght=lengthNumber(num);
    cout<<"Length of number is ";
    cout<<lenght<<"\n";
    return 0;
}