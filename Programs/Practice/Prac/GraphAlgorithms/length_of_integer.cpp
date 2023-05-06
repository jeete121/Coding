#include <bits/stdc++.h>
using namespace std;
//function to find the legth
//of given number
int lengthNumber(int num)
{
    int length=0;
    //iterate tiil the 
    //number becomes 0
    while(num>0)
      {
          //increment the length
          length++;
          //num=num/10
          num=num/10;
      }
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