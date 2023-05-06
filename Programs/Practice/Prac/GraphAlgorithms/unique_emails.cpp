#include <bits/stdc++.h>
using namespace std;


//function to count the number of
//unique emails
int numUniqueEmails(vector<string>& emails) 
{
        set<string> st;

        //iterate till the length of emails
        for(int i=0;i<emails.size();i++)
         {
           string str="";
           int j=0;
           string S=emails[i];

           //iterate till the size of current 
           //email or we get '@' 
            while(j<S.size()&&S[j]!='@')
             {
                 //if . then move to next position
               if(S[j]=='.')
                  j++;
             //if + then break
                else if(S[j]=='+')
                {
                    break;                    
                }
               //if not + and not . then 
               //add this into the string and
               //move forward 
                else
                {
                    str+=S[j];
                    j++;
                }
                
             }

        //iterate we get '@'
        while(j<S.size()&&S[j]!='@')
               j++;
         str+=S.substr(j);
            st.insert(str);
         }
        //return the size of stack
      return st.size();
}
int main()
{
    vector<string> emails={"test.email+alex@gmail.com","test.e.mail+bob.cathy@gmail.com"
                 ,"testemail+david@gma.il.com"};
    cout<<numUniqueEmails(emails);
    return 0;
}
