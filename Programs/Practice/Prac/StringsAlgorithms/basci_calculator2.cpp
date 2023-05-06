#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
        if(op=='*'||op=='/')
              return 1;
        if(op=='+'||op=='-')
              return 0;
        return -1;
}
int calculate(string s) 
{
        stack<char> op;
        stack<int> val;
        int n=s.size();
        for(int i=0;i<n;i++)
         {
            if(s[i]==' ')
                  continue;
            else if(s[i]=='(')
                  op.push(s[i]);
            else if(isdigit(s[i]))
            {
                int x=0;
                while(i<n&&isdigit(s[i]))
                {
                    x=(x*10)+(s[i]-'0');
                    i++;
                }
                val.push(x);
                i--;
            }
          else if(s[i]==')')
           {
              while(!op.empty()&&op.top()!='(')
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
              if(!op.empty())
                    op.pop();
           }
          else
          {
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
      return val.top();
}
int main()
{
  string str="3+2*2";
  cout<<calculate(str);
  return 0;
}