#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string S, string T) 
{

        stack<char> s1;
        stack<char> s2;
        for (int i = 0; i < S.length(); i++) 
        {
            if (S[i] == '#' && !s1.empty()) {
                s1.pop();
            } else if (S[i] != '#') {
                s1.push(S[i]);
            }
        }
        for (int i = 0; i < T.length(); i++) {
            if (T[i] == '#' && !s2.empty()) {
                s2.pop();
            } else if (T[i] != '#') {
                s2.push(T[i]);
            }
        }
        if (s1.size() != s2.size())
            return false;
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() != s2.top())
                return false;
             s1.pop();
             s2.pop();
        }

        return true;

}
int main()
{
    string S = "y#fo##f";
    string T = "y#f#o##f";
    if(backspaceCompare(S, T))
       cout<<"true";
    else
      cout<<"false";
    return 0;
}

