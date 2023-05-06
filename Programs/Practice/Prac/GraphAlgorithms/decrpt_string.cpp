#include <bits/stdc++.h>
using namespace std;
//function to deecrypt String from 
//Alphabet to Integer Mapping
string freqAlphabets(string s) 
{
     map<string,string> mp;
     for(int i=1;i<=9;i++)
           mp[to_string(i)]='a'+i-1;
     for(int i=10;i<=26;i++)
     {
         string x=to_string(i);
         x+="#";
         mp[x]=i-1+'a';
     }
   string res="";
        int i=0,n=s.size();
  while(i<n)
    {
        string str="";
       if((i+2)<n)
       {
           if(s[i+2]=='#')
           {
               str+=s[i];
               str+=s[i+1];
               str+=s[i+2];
               i+=3;
           }
          else
          {
              str+=s[i];
              i++;
          }
       }
      else
      {
          str+=s[i];
          i++;
      }
       res+=mp[str]; 
    }
        return res;
    }
int main()
{
    string str="10#11#12";
    string convert=freqAlphabets(str);
    cout<<convert<<"\n";
    return 0;
}
