#include <bits/stdc++.h>
using namespace std;
//function to check string is Palindrome
bool isPalindrome(string s)
{

    //store the each charater into
    //the vector only alphanumeric values
    vector<char> v;
     for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {

                //convert into the lower case
                if(s[i]>='A'&&s[i]<='Z')
                       s[i]=s[i]+32;
                  v.push_back(s[i]);
            }
            if(isdigit(s[i]))
                   v.push_back(s[i]);
                 
        }
    //check for palindrome
      int i=0,j=v.size()-1;
        while(i<j)
        {

            //if correspondings are not
            //equal return false
            if(v[i]!=v[j])
                   return false;
            i++;
            j--;
        }
    //return true
      return true;
}
int main()
{
    string str = "A man, a plan, a canal: Panama";
        if (isPalindrome(str)) {
            cout<<"true";;
        } else {
            cout<<"false";
    }
}

