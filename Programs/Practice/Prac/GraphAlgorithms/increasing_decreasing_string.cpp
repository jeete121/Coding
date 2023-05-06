#include <bits/stdc++.h>
using namespace std;


string sortString(string s) 
{
    string res="";
    int n=s.size();
    int f[26]={0};
    for(int i=0;i<n;i++)
        f[s[i]-'a']++;
    int i=0;
     while(n>0)
        {
            i=0;

            //increasing string
            while(i<26 &&n)
            {
                if(f[i]>0)
                {
                    res+='a'+i;
                    n--;
                    f[i]--;
                }
               i++;
            }
            i=25;

            //decreasing string
            while(i>=0&&n)
            {
                if(f[i]>0)
                {
                    res+='a'+i;
                    n--;
                    f[i]--;
                }
              i--;
            }
     }
      return res;
}
int main()
{
    string str="rat";
    cout<<sortString(str);
    return 0;
}

