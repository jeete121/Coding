#include <bits/stdc++.h>
using namespace std;

string strSort(string s) 
{
        vector<char> ch;
        for(int i=0;i<s.size();i++)
          ch.push_back(s[i]);
        int size = ch.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (ch[i] > ch[j]) {
                    char temp = ch[i];
                    ch[i] = ch[j];
                    ch[j] = (char) temp;
                }
            }
        }
      s="";
      for(int i=0;i<size;i++)
        s+=ch[i];
    return s;
}
int main()
{
     string s = "ramsingh";
     cout<<strSort(s);
     return 0;
}

