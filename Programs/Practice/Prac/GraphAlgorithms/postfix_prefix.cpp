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
}string infixToPrefix(string infix)
{      
     string prefix = "";
    // stack for hold operator
    stack<char> stack;

    //revers the infix string
    reverse(infix.begin(),infix.end());
    // Iterate till given infix length
    for (int i = 0; i < infix.size(); i++)
     {
        // hold char from infix
        char c = infix[i];
        // If letter then add into prefix
         if (isalpha(c)) {
                prefix += c;
            } 
        else if (c == ')') 
        {
                stack.push(c);
        } 
        else if (c == '^')
          {
                stack.push(c);
         } 
        else if (c == '(')
              { // if closing ( then
                // iterate till ) and add into prefix
                while (!stack.empty() && stack.top() != ')') {
                    {
                        prefix += stack.top();
                        stack.pop();
                    }
                }
                // if last char is ')' into stack then pop
                if (!stack.empty() && stack.top() == ')')
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
                            prefix += stack.top();
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
                prefix += stack.top();
                stack.pop();
           }
        }
      reverse(prefix.begin(),prefix.end());
        return prefix;
}
//unction to convert from
//postfix to infix
string postfixToInfix(string postFIx) 
{ 
    string infix = "";
    //stack for hold operator
    stack<string> stack;
    // Iterate till given postfix length
    for (int i = 0; i < postFIx.size(); i++)
      {
        //hold char from postFIx
         char c = postFIx[i];
        // If letter then add into stack
        if (isalpha(c)) 
           {
               //convert from character
               //to string
                string strc(1,c);
                stack.push(strc);
           } 
        else 
          {
              // rule = second+operator+first
                string a = stack.top();
                stack.pop();
                string b = stack.top();
                stack.pop();

                //convert from character
                //to string
                string strc(1,c);
                stack.push(b + "" + strc + "" + a);
            }

        }
        //iterate till stack is empty
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
   // postfix
   string postFIx = "ABC*+EF/GH^*+";
   

   //initialize the operator
   //precedence
   operatorPrecedence();
   //postfix to infix
   string infix = postfixToInfix(postFIx);
   
   //infix to prefix
   string prefix=infixToPrefix(infix);
   cout<<"Prefix is ";
   cout<<prefix<<"\n";
   return 0;
}