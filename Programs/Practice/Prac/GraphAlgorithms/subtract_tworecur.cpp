#include <bits/stdc++.h>
using namespace std;
//function to subtract number
//without using '-' operator
int subtractWithoutOperatorRecursive(int a,int b)
{
    if(b==0)
       return a;
    return subtractWithoutOperatorRecursive(a^b,(~a&b)<<1);
}
int main()
{
    int a=7,b=8;
    int subtract=subtractWithoutOperatorRecursive(a,b);
    cout<<"Subtract is ";
    cout<<subtract<<"\n";
    return 0;
}