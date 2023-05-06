#include <bits/stdc++.h>
using namespace std;


//function to reverse the character 
//array
void reverseString(char str[],int n)
{
   for(int i=0;i<n/2;i++)
     {

         //swapping the charater
         char temp=str[i];
         str[i]=str[n-i-1];
         str[n-i-1]=temp;
     }
}
int main()
{
    char str[] = { 'a', 'g', 'p', 'd' };
    int n=sizeof(str)/sizeof(str[0]);
    reverseString(str,n);
    for(int i=0;i<n;i++)
      cout<<str[i]<<" ";
    return 0;
}