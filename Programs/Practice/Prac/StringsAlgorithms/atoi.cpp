#include <bits/stdc++.h>
using namespace std;

int myAtoi(string str) 
{
        int n=str.size();
        int i=0;

        //itearte till their is spaces
        while(i<n&&str[i]==' ')
              i++;
        if(str[i]=='+')
        {
            i++;
            if(str[i]=='-'||str[i]=='+')
                return 0;
        }
        if(str[i]!='-'&&(!isdigit(str[i])))
              return 0;
        string res="";
        for(int j=i;j<str.size();j++)
               res+=str[j];
    stringstream str1(res);
    int x = 0; 
    str1>> x; 
        return x;
}
int main()
{
   string str="4193 with words";
   cout<<myAtoi(str);
   return 0;
}
