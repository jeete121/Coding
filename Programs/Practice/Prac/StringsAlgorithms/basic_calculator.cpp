#include <bits/stdc++.h>
using namespace std;

//function to find the precedence of
//the operators
int precedence(char op)
{
        if(op=='*'||op=='/')
              return 1;
        if(op=='+'||op=='-')
              return 0;
        return -1;
}

//function to solve the given
//equation
int calculate(string s) 
{

   //operator stack
    stack<char> op;
  //value stack
    stack<int> val;
    int n=s.size();

    //iterate till the length of string
    for(int i=0;i<n;i++)
         {

            //if space then continue
            if(s[i]==' ')
                  continue;

           //if open bracket then push into the
           //operator stack
            else if(s[i]=='(')
                  op.push(s[i]);

           //if digit 
            else if(isdigit(s[i]))
            {
                int x=0;

                //find the complete number till we get digits
                while(i<n&&isdigit(s[i]))
                {
                    x=(x*10)+(s[i]-'0');
                    i++;
                }

                //push into the value stack
                val.push(x);
                i--;
            }
        //if closing bracket
          else if(s[i]==')')
           {

              //iterate till the operator top
              //is not open brack and operator stack is not 
              //empty
              while(!op.empty()&&op.top()!='(')
              {

                  //pop two values from value stack
                  int val1=val.top();
                  val.pop();
                  int val2=val.top();
                  val.pop();
                  //pop the operator from operator stack
                  char c=op.top();
                  op.pop();

                  //if +
                  if(c=='+')
                        val.push(val2+val1);

                 // if -
                  else if(c=='-')
                         val.push(val2-val1);

                  //if *
                  else if(c=='*')
                         val.push(val2*val1);

                  //if /
                  else
                        val.push(val2/val1);
              }
               //if operator stack is not empty
               //then pop from operator stack 
              if(!op.empty())
                    op.pop();
           }
          else
          {

              //now according to precendence 
              while(!op.empty()&&precedence(op.top())>=precedence(s[i]))
              {
                  int val1=val.top();
                  val.pop();
                  int val2=val.top();
                  val.pop();
                  char c=op.top();
                  op.pop();
                    if(c=='+')
                        val.push(val2+val1);
                  else if(c=='-')
                         val.push(val2-val1);
                  else if(c=='*')
                         val.push(val2*val1);
                  else
                        val.push(val2/val1);
              }
              op.push(s[i]);
          }
         }

         //now while operator stack is not
         //empty
         while(!op.empty())
              {
                  int val1=val.top();
                  val.pop();
                  int val2=val.top();
                  val.pop();
                  char c=op.top();
                  op.pop();
                    if(c=='+')
                        val.push(val2+val1);
                  else if(c=='-')
                         val.push(val2-val1);
                  else if(c=='*')
                         val.push(val2*val1);
                  else
                        val.push(val2/val1);
              }

       //return the final result
      return val.top();
}
int main()
{
   string str="1+1";
   cout<<calculate(str);
   return 0;
}


