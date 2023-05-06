#include <bits/stdc++.h>
using namespace std;


//function to remove outer parentheses
//from the string
string removeOuterParentheses(string S)
{
    stack<char> st;
    int n = S.size();
    vector<string> res;
    string str = "";

    //iterate till the length of
    //the string
    for (int i = 0; i < n; i++)
    {

        //if open bracket then 
        //push into the stack
        //and append into the new string
        if (S[i] == '(')
        {
            st.push(S[i]);
            str += S[i];
        }

        //if closing bracket then pop 
        //from the stack and add the current
        //into the new string
        else
        {
            st.pop();
            str += S[i];

            //if stack is empty 
            //then reset str
            if (st.empty())
            {
                res.push_back(str);
                str = "";
            }
        }
    }
    string ans = "";
    for (int i = 0; i < res.size(); i++)
    {
        string x = res[i];
        for (int j = 1; j < x.size() - 1; j++)
            ans += x[j];
    }
    return ans;
}

int main()
{
    string str = "(()())(())";
    cout << removeOuterParentheses(str);
    return 0;
}