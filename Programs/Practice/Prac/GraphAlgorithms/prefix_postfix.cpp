#include <bits/stdc++.h>
using namespace std;
map<char,int> precedence;
map<char,int> operatorPrecedence() 
{
        precedence['^']=10;
        precedence['*']=9;
        precedence['/']=9;
        precedence['-']=8;
        precedence['+']=8;
        return precedence;
}


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
string infixToPostfix(string infix)
{      
     string postFix = "";
    // stack for hold operator
    stack<char> stack;
    // Iterate till given infix length
    for (int i = 0; i < infix.size(); i++)
     {
        // hold char from infix
        char c = infix[i];
        // If letter then add into postfix
         if (isalpha(c)) {
                postFix += c;
            } 
        else if (c == '(') 
        {
                stack.push(c);
        } 
        else if (c == '^')
          {
                stack.push(c);
         } 
        else if (c == ')')
              { // if closing ) then
                // iterate till ( and add into postfix
                while (!stack.empty() && stack.top() != '(') {
                    {
                        postFix += stack.top();
                        stack.pop();
                    }
                }
                // if last char is '(' into stack then pop
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
            } else {
                // if precedence of c is greater then 
                //top stack then add
                if (stack.empty() || precedence[c] >
                     precedence[stack.top()]) {
                    stack.push(c);
                } else {
                    // iterate till precedence is less then equal and add
                    while (!stack.empty() && precedence[c] 
                            <= precedence[stack.top()]) {
                        {
                            postFix += stack.top();
                            stack.pop();
                        }
                    }
                    // add coming char
                    stack.push(c);
                }
            }

        }
        // iterate till stack is empty
        while (!stack.empty()) {
           {
                postFix += stack.top();
                stack.pop();
           }
        }
        return postFix;
}
int main()
{
   // prefix
   string prefix = "+A+*BC*/EF^GH";
   // precedence initialization
   operatorPrecedence();
   // prefix to infix

   string infix=prefixToInfix(prefix);

   //infix to postfix
   string postFIx = infixToPostfix(infix);
   cout<<"Postfix is ";
   cout<<postFIx<<"\n";
   return 0;
}