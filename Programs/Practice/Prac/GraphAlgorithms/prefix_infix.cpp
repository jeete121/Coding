#include <bits/stdc++.h>
using namespace std;

//function to convert from
//prefix to infix
string prefixToInfix(string prefix) 
{
    string infix = "";
    // stack for hold operator
    stack<string> stack;
    // Iterate till given prefix length
    for (int i = prefix.length() - 1; i >= 0; i--) 
    {
        // hold char from postFIx
        char c = prefix[i];
        // If letter then add into stack
        if (isalpha(c))
           {
               //convert character 
               //to string 
               string strc(1,c);
               stack.push(strc);
           } 
        else 
         {
                // rule = first+operator+second
                string a = stack.top();
                stack.pop();

                string b = stack.top();
                stack.pop();
                //convert from character
                //to string
                string strc(1,c);
                stack.push(a + "" + strc + "" + b);
            }

        }
        // iterate till stack is empty
        while (!stack.empty()) {
            {
                infix += stack.top();
                stack.pop();
            }
        }
        return infix;
}
int main()
{
   // prefix
    string prefix = "+A+*BC*/EF^GH";
   // prefix to infix
   string infix = prefixToInfix(prefix);
    cout<<"Infix is ";
    cout<<infix<<"\n";
    return 0;
}

