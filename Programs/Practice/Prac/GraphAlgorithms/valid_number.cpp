#include <bits/stdc++.h>
using namespace std;

//function to check if the number
//represented by string is valid or not
bool isNumber(string s) 
{
    int n=s.size();
    int digit=0,dots=0;
    int i=0;

    //iterate till their is spaces
    //in start of number
    while(i<n&&s[i]==' ')
              i++;
    //if positive sign or negaitve sign
    if(s[i]=='+'||s[i]=='-')
              i++;
   while(i<n)
        {
            if(isdigit(s[i]))
            {
                digit++;
                i++;
            }
            else if(s[i]=='.')
            {
                dots++;
                i++;
            }
            else
                  break;
      }

      //if their is no digits and
      // and we have dots then return false
     if(digit==0||dots>1)
              return false;
    
    //if thier is exponent
     if(s[i]=='e')
        {
            i++;
            //if + ,- sign
            if(s[i]=='+'||s[i]=='-')
                  i++;
           
            digit=0;
            while(i<n)
            {
                if(isdigit(s[i]))
                {
                    i++;
                    digit++;
                }
                else
                     break;
            }

        //if no digits retunr false
          if(digit==0)
                return false;
            
        }
     //if spaces move to next
        while(i<n&&s[i]==' ')
              i++;
        //if we not reach at end the return false
        if(i<n)
              return false;

      //else number is valid 
        return true;
}
int main()
{
  string s="3";
  if(isNumber(s))
    cout<<"true\n";
  else
    cout<<"false\n";
   return 0;
 
}