#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t,a,b,c,r;
    cin>>t;
    while(t--)
    {
        long long res;
        cin>>a>>b>>c>>r;
        if(a>b)
        {
            long long temp=a;
            a=b;
            b=temp;
        }
        if(r==0)
            res=b-a;
        if(a==c && b==c)
            res=0;
        else if(a==c && b!=c)
        {
                if(r<=(b-c))
                     res=b-c-r;
                else
                    res=0;
        }
        else if(a!=c && b==c)
        {

                if(r<=(c-a))
                    res=c-a-r;
                else
                    res=0;
        }
        else if(c>a && c<b)
        {
            if(r<=(b-c) && r<=(c-a))
                 res=b-a-2*r;
            else if(r<=(b-c)&& r>=(c-a))
                 res=b-c-r;
            else if(r>=(b-c)&& r<=(c-a))
                   res=c-a-r;
            else if(r>=(b-c) && r>=(c-a))
                    res=0;
        }
        else if(c<a)
        {
            if(r<=(a-c))
                 res=b-a;
            else if(r>=(a-c)&& r<=(b-c))
                   res=b-c-r;
            else if(r>=(a-c)&& r>=(b-c))
                   res=0;
        }
        else if(c>b)
        {
            if(r<=(c-b))
                 res=b-a;
            else if(r>=(c-b)&& r<=(c-a))
                  res=c-a-r;
            else if(r>=(c-b)&& r>=(c-a))
                  res=0;
        }
     cout<<res<<"\n";
    }
     return 0;
}
