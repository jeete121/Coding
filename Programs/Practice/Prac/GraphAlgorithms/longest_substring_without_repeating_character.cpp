#include <bits/stdc++.h>
using namespace std;

//function to find the length of 
//longest substring without
//repeating character
int lengthOfLongestSubstring(string s) 
{
      unordered_set<char> st;
      int n=s.size();
        int max1=0;
      //iterate till the length
      //of string
      for(int i=0;i<n;i++)
      {
          int len=st.size();
          st.insert(s[i]);
          //if previous len is same 
          //as new length then the new character 
          //occurs prevoius
          if(len==st.size())
            {
                //update the maximum 
                //length
               if(len>max1)
                      max1=len;

              //clear the set
              st.clear();

              //now insert into the set till we get
              //the same character as current
              //prevoiusly
              for(int j=i-1;s[j]!=s[i];j--)
                     st.insert(s[j]);
              //insert the current element
              st.insert(s[i]);
            }
          else
          {
              //uodate the maximum length
              if(st.size()>max1)
                     max1=st.size();
          }
      }
        return max1;
}
int main()
{
    string str="abcabcbb";
    int length=lengthOfLongestSubstring(str);
    cout<<length<<"\n";
    return 0;
}

