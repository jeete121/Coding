#include <bits/stdc++.h>
using namespace std;

int balancedStringSplit(string s) 
{
    int n=s.size();
    int cnt=0,L=0,R=0;
    for(int i=0;i<n;i++)
     {
           if(s[i]=='R')
                  R++;
            else if(s[i]=='L')
                  L++;
            //count of L and R
            //  are same then increment count and
            //reset L and R
            if(L==R)
            {
                cnt++;
                L=0;
                R=0;
            }
      }
    return  cnt;
}
int main()
{
    string str="RLRRLLRLRL";
    int count=balancedStringSplit(str);
    cout<<count<<"\n";
    return 0;
}
