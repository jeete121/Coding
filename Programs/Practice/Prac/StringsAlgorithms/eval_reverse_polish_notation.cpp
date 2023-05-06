#include <bits/stdc++.h>
using namespace std;


//function to evaluate the reverse polish
//notation 
int evalRPN(vector<string>& tokens) 
{
        int res=0;
        stack<int> st;
        int n=tokens.size();
        if(n==0)
              return res;
        for(int i=0;i<n;i++)
        {
            //if the current token is the operator
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int rem;
                //pop top two elements from stack
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();

                //if + 
                if(tokens[i]=="+")
                      rem=y+x;

                //if -
                else if(tokens[i]=="-")
                       rem=y-x;

                //if *
                else if(tokens[i]=="*")
                       rem=y*x;

                //if /
                else if(tokens[i]=="/")
                       rem=y/x;
                 //push into the stack
                st.push(rem);
                       
            }

            //push into the stack
            else
            {
                
                int x=stoi(tokens[i]);
                st.push(x);
            }
        }
     //return the top of stack
    return st.top();
}
int main()
{ 
   vector<string > str={"2", "1", "+", "3", "*"};
   cout<<evalRPN(str);
   return 0;
}


