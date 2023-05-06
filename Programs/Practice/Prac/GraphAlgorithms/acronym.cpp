#include <bits/stdc++.h>
using namespace std;

string acronym(int k, vector<string> &s,
               int n, vector<string> &str)
{
    set<string> st;
    for (int i = 0; i < k; i++)
    {

        st.insert(s[i]);
    }

    string res = "";
    for (int i = 0; i < n; i++)
    {
        if (st.find(str[i]) == st.end())
        {
            if (str[i][0] >= 'a' && str[i][0] <= 'z')
                res += str[i][0] - 32;
            else
                res += str[i][0];
            if (i < n - 1)
                res += '.';
        }
    }
    string ans = "";
    int len = res.size();
    for (int i = 0; i < len - 1; i++)
        ans += res[i];
    if (res[len - 1] != '.')
        ans += res[len - 1];
    return ans;
}
int main()
{
    int k = 5;
    vector<string> s = {"hey", "girls", "i", "am", "single"};

    int n = 11;
    vector<string> str = {"hey", "all", "boys",
                          "and", "girls",
                          "welcome", "to",
                          "hackerearth", "easy",
                          "september", "challenge"};

    cout << acronym(k, s, n, str) << "\n";
    return 0;
}