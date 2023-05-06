#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) 
{
        string str[n];
        str[0]="1";
        if(n==1)
              return "1";
        str[1]="11";
        for(int i=2;i<n;i++)
        {
            string x="";
            string p=str[i-1];
            int cnt=1;
            int j=0;
        while(j<p.size())
        {
            cnt=1;
            while(j<p.size()&& p[j]==p[j+1])
            {
                cnt++;
                j++;
            }
             x+=to_string(cnt);
             x+=p[j];
             j++;
            }
            str[i]=x;
        }
        return str[n-1];
}
int main()
{
    int n=4;
    cout<<countAndSay(n);
    return 0;
}

