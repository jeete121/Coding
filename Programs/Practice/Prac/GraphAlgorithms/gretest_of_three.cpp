#include <bits/stdc++.h>
using namespace std;
//function to find greatest of three
//numbers
int findGreatest(int a,int b,int c)
{
    //if a is greate  than or eqaul to 
    // both b and c
    if(a>=b&&a>=c)
      return a;
    //if b is greater than or equal to 
    //both a and c
    else if(b>=a&&b>=c)
       return b;
    //if c is greater than or equal to 
    //both b and c
    return c;
}
int main()
{
    int a=3,b=7,c=2;
    int greatest=findGreatest(a,b,c);
    cout<<"Greatest is ";
    cout<<greatest<<"\n";
    return 0;
}