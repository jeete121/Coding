#include <bits/stdc++.h>
using namespace std;

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
   //postfix to infix
   string infix = postfixToInfix(postFIx);
   cout<<"Infix is ";
   cout<<infix<<"\n";
   return 0;
}