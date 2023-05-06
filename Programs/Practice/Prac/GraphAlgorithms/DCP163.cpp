#include <bits/stdc++.h>
using namespace std;

int reversePolishNotation(vector<string> &tokens)
{
    int res = 0;
    stack<int> st;
    int n = tokens.size();
    if (n == 0)
        return res;
    for (int i = 0; i < n; i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int rem;
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            if (tokens[i] == "+")
                rem = y + x;
            else if (tokens[i] == "-")
                rem = y - x;
            else if (tokens[i] == "*")
                rem = y * x;
            else if (tokens[i] == "/")
                rem = y / x;
            st.push(rem);
        }
        else
        {
            int x = stoi(tokens[i]);
            st.push(x);
        }
    }
    return st.top();
}
int main()
{
    vector<string> tokens = {"15", "7", "1", "1",
                             "+", "-", "/", "3", "*",
                             "2", "1", "1", "+", "+", "-"};

    cout << reversePolishNotation(tokens) << "\n";

    return 0;
}