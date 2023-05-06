#include <bits/stdc++.h>
using namespace std;


int minPartitions(string n) 
{
    int ans=0;

    //iterate till length of string and
    //find the maximum digits
    for(int i=0;i<n.size();i++)
         ans=max(ans,n[i]-'0');
    return ans;
}
int main()
{
    string n="32";
    cout<<minPartitions(n);
    return 0;
}

