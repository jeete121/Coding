#include <bits/stdc++.h>
using namespace std;

//function to check for 
//vowel or not
bool isVowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
       return true;
    if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
       return true;
    return false;
}
//function to reverse the vowels in string
string reverseVowels(string s)
{
        int l = s.size();
        int high = l - 1;
        int low = 0;
        // iterate till low<=high
        // two pointer approach
        while (low <= high) {
            while (!isVowel(s[low]) && low < high) {
                low++;
            }
            while (!isVowel(s[high]) && low < high) {
                high--;
            }
            if (low < high) {
               char temp=s[low];
               s[low]=s[high];
               s[high]=temp;
            }
            low++;
            high--;
        }
    return s;
}
int main()
{
    string str = "hello";
    string revStr = reverseVowels(str);
    cout<<revStr;
    return 0; 
}

