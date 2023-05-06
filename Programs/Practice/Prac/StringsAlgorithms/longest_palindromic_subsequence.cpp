#include <bits/stdc++.h>
using namespace std;
int LCP(string X,,int i,int j)
 {
     if(i>j)
       return 0;
     if(i==j)
       return 1;
     
 }
int main()
{
    string X;
    cin>>X;
    cout<<LCP(X,0,X.size())<<"\n";
    return 0;
}