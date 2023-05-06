#include <bits/stdc++.h>
using namespace std;

//function to find the maximum
//69 
int maximum69Number (int num) 
{
        string str="";
        while(num)
        {
            int x=num%10;
            str+=to_string(x);
            num=num/10;
        }
       reverse(str.begin(),str.end());
       for(int i=0;i<str.size();i++)
              if(str[i]=='6')
              {
                  str[i]='9';
                  break;
              }
      stringstream f(str);
        int maximum=0;
        f>>maximum;
        return maximum;
} 
int main()
{
    int num=9669;
    int maximum=maximum69Number(num);
    cout<<maximum<<"\n";
    return 0;
} 
