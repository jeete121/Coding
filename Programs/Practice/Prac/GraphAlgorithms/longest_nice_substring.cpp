#include <bits/stdc++.h>
using namespace std;

string longestNiceSubstring(string s)
{
    //if size of string is less than
    //2 then return null string
    //base case
    if (s.size() < 2)
        return "";
    unordered_set<char> st;

    //add all characters of string into
    //the unordered set
    for (int i = 0; i < s.size(); i++)
        st.insert(s[i]);
    for (int i = 0; i < s.size(); i++)
    {
        if (st.find(toupper(s[i])) == st.end() || st.find(tolower(s[i])) == st.end())
        {
            //call for left half
            string s1 = longestNiceSubstring(s.substr(0, i));

            //call for right half
            string s2 = longestNiceSubstring(s.substr(i + 1));

            //return the string which is bigger
            if (s1.size() >= s2.size())
                return s1;
            return s2;
        }
    }

    return s;
}

int main()
{
    string s = "YazaAay";

    cout << longestNiceSubstring(s) << "\n";

    return 0;
}