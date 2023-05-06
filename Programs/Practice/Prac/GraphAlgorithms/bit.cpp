#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a=10;
    int b=25;

    //if any one is 1 then the
    //result is 1 for or
    cout<<"a|b is "<<(a|b)<<"\n";

    //if both are set then the result
    //is set else result is unset
    cout<<"a&b is "<<(a&b)<<"\n";

    //if one is set and other is
    //unset  then the result is
    //1 else 0
    cout<<"a^b is "<<(a^b)<<"\n";
    return 0;
}