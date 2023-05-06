#include <bits/stdc++.h>
using namespace std;
//function to check valid
//parentheses
bool isValid(string s)
{
    //stack to hold the opening brackets
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        //if open bracket push into the stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            //stack is empty
            if (st.empty())
                return false;
            //closing bracket not matches with the top
            //of stack return false
            else if (s[i] == ')' && st.top() != '(')
                return false;
            else if (s[i] == ']' && st.top() != '[')
                return false;
            else if (s[i] == '}' && st.top() != '{')
                return false;
            st.pop();
        }
    }
    if (!st.empty())
        return false;
    return true;
}
int main()
{
    string str = "([])[]({})";
    if (isValid(str))
        cout << "Valid Parentheses\n";
    else
        cout << "Not Valid Parenthese\n";
    return 0;
}
//Time Complexity:O(n)
//Space Complexity:O(n)