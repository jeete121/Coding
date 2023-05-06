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
   // infix
   string infix = "A+B*C+(E/F)*G^H";
   // precedence initialization
   operatorPrecedence();
   // infix to postfix
   string postFIx = infixToPostfix(infix);
   cout<<"Postfix is ";
   cout<<postFIx<<"\n";
   return 0;
}