#include <bits/stdc++.h>
using namespace std;
//function to check string is Palindrome
bool isPalindrome(string s) 
{
    // hold length start and end
     int left = 0;
     int right = s.length() - 1;
    // iterate untill left less then right
    while (left < right) 
    {
            // iterate untill not letter or digit from beginning
            while (left < right && !isalpha(s[left])&&!isdigit(s[left])) {
                left++;
            }
            // convert lower case
            if(s[left]>='A'&&s[left]<='Z')
              s[left]=s[left]+32;

            // iterate untill not letter or digit from end
          while (left < right && !isalpha(s[right])&&!isdigit(s[right])) {
                right--;
            }
            // convert lower case
            if(s[right]>='A'&&s[right]<='Z')
              s[right]=s[right]+32;
            // if !equals then false
            if (s[left]!=s[right])
                return false;

            left++;
            right--;
        }
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

