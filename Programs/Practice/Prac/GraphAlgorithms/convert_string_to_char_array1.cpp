#include <bits/stdc++.h>
using namespace std;

//function to convert from 
//string to character array
void  stringCharArray(string str)
{
    char ch[str.size()];
    strcpy(ch,str.c_str());
    cout<<"[";
    for(int i=0;i<str.size();i++)
       {
           if(i!=str.size()-1)
              cout<<ch[i]<<", ";
           else
             cout<<ch[i];
           
       }
      cout<<"]";
}
int main()
{
    string str="Hello World";
    stringCharArray(str);
            
    return 0;

}