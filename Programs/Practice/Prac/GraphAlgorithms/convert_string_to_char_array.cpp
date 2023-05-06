#include <bits/stdc++.h>
using namespace std;

//function to cinvert from 
//string to character array
vector<char> stringCharArray(string str)
{
    vector<char> ch;
    for(int i=0;i<str.size();i++)
        ch.push_back(str[i]);
    return ch;
}
int main()
{
    string str="Hello World";
    vector<char> ch=stringCharArray(str);
    cout<<"[";
    for(int i=0;i<ch.size();i++)
        {
            if(i!=ch.size()-1)
              cout<<ch[i]<<", ";
            else
              cout<<ch[i];
        }
        cout<<"]";
            
    return 0;

}