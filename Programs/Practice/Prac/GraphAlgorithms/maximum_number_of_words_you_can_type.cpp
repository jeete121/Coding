#include <bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string brokenLetters)
{

    set<char> st;
    for (int i = 0; i < brokenLetters.size(); i++)
    {
        st.insert(brokenLetters[i]);
    }

    int i = 0;
    int flag = 0;
    int cnt = 0;
    int n = text.size();
    while (i < n)
    {
        flag = 0;
        while (i < n && text[i] == ' ')
            i++;
        while (i < n && text[i] != ' ')
        {
            if (st.find(text[i]) != st.end())
            {
                flag = 1;
            }
            i++;
        }
        if (flag == 0)
            cnt++;
    }

    return cnt;
}

int main()
{
    string text = "hello world", brokenLetters = "ad";

    cout << canBeTypedWords(text, brokenLetters) << "\n";

    return 0;
}