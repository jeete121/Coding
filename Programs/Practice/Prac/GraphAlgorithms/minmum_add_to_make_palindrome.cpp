#include <bits/stdc++.h>
using namespace std;

//function to find the number
//of add to make string valid
int minAddToMakeValid(string s) 
{
    stack<char> st;
    int cnt=0;
    int  n=s.size();

    //iterate till the length of string
    for(int i=0;i<n;i++)
        {

            //if open bracket push into
            //the stack
            if(s[i]=='(')
                  st.push(s[i]);

            //if closing bracket
            else if(s[i]==')')
            {

                //if stack is empty increment
                //the count
                if(st.empty())
                      cnt++;

                //else pop from the stack
                else
                    st.pop();
            }
                
        }
   //uodate the count   
   cnt+=st.size();

   //return the count 
    return cnt;
}
int main()
{
    string str="())";
    cout<<minAddToMakeValid(str);
    return 0;
}

