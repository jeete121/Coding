#include <bits/stdc++.h>
using namespace std;

string longestSubstring(string s, int k)
{
    string maxLengthString = "";

    if (s.length() != 0 && k != 0)
    {
        string window = "";
        set<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (st.size() == k && st.find(ch) == st.end())
            {
                // Fetch the last index of the first character
                // at window.
                // Discard the string before the last index.
                int index = 0;
                for (int j = window.size() - 1; j >= 0; j--)
                {
                    if (window[j] == window[0])
                    {
                        index = j;
                        break;
                    }
                }

                window = window.substr(index + 1);
                st.clear();
                for (int j = 0; j < window.size(); j++)
                {
                    st.insert(window[j]);
                }
            }
            st.insert(ch);
            window += ch;
            if (window.size() > maxLengthString.size())
            {
                maxLengthString = window;
            }
        }
    }

    return maxLengthString;
}

int main()
{
    string s = "abcba";
    int k = 2;

    cout << longestSubstring(s, k) << "\n";

    return 0;
}