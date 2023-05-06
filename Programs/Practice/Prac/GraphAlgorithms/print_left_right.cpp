#include <bits/stdc++.h>
using namespace std;

void printTriangle(int n) 
{

    //print triangle in increasing
    //no of columns
   for(int i=1;i<=n/2;i++)
     {
         for(int j=1;j<=i;j++)
            cout<<"* ";
        cout<<"\n";
     }
     //print the middle one
    for(int i=1;i<=(n+1)/2;i++)
       cout<<"* ";
    cout<<"\n";
//print triangle in decreasing
  for(int i=n/2;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
           cout<<"* ";
      cout<<"\n";
    }
     
}
int main()
{
    //n should be odd 
    int n = 9;
    printTriangle(n);
}