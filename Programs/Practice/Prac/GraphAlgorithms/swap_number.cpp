#include <bits/stdc++.h>
using namespace std;
//function to swap two varibales
//without using third variable
void swapTwoNumber(int &a,int &b)
{
    a=a*b;
    b=a/b;
    a=a/b;
}
int main()
{
    int a=10,b=24;
    cout<<"Numbers before swap\n";
    cout<<"a = "<<a<<" b = "<<b<<"\n";
    swapTwoNumber(a,b);
    cout<<"Numbers after swap\n";
    cout<<"a = "<<a<<" b = "<<b<<"\n";
    return 0;
}

