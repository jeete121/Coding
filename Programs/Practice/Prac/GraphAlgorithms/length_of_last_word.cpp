#include <bits/stdc++.h>
using namespace std;

//function to find last word length
int lengthOfLastWord(string s)
{
   int length = 0;
   for (int i = s.length() - 1; i >= 0; i--) {
   // after start letter not character, then return length
     if (length > 0 && s[i]==' ') {
                return length;
      }
     // if found letter then increase count
     if (s[i]!=' ') {
                length++;
      }

     }
        return length;
}

int main()
{
    string str = "Hello Words ";
    int length = lengthOfLastWord(str);
    cout<<"Length is "<<length;
    return 0;
}