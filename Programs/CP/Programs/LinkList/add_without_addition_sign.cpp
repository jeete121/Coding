#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int res=a;
    int carry;
    while(b)
     {
        carry=a&b;
        a=a^b;
        res=a;
        b=carry<<1;
     }
     cout<<res<<"\n";
     return 0;
}