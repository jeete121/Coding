#include <bits/stdc++.h>
using namespace std;


string strWithout3a3b(int A, int B) 
{
    string res="";
    while(A||B)
        {
          if(res.size()>=2&&res[res.size()-1]=='a'&&res[res.size()-2]=='a')
          {
              res+='b';
              B--;
          }
         else if(res.size()>=2&&res[res.size()-1]=='b'&&res[res.size()-2]=='b')
         {
             res+='a';
             A--;
         }
            else
            {
                if(A>B)
                {
                    res+='a';
                    A--;
                }
                else
                {
                    res+='b';
                    B--;
                }
            }
        }
        return res;
}
int main()
{
    int a=4,b=1;
    cout<<strWithout3a3b(a,b);
    return 0;
}
