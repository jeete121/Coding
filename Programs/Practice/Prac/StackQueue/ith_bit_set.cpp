#include <bits/stdc++.h>
using namespace std;

//function to check the ith bit
// if set return true else
//return false
bool isIthBitSet(int n,int i)
{
    return n&(1<<(i-1));
}
int main()
{
    //1011
    int n=11;
    int i=2;
    if(isIthBitSet(n,i))
       cout<<"Ith bit is set\n";
    else
     cout<<"Not set\n";
}