#include <bits/stdc++.h>
using namespace std;

void generate(vector<string> &res,string cur,int open,
   int close,int max1) 
{ 
        if(cur.length()== max1*2)  
           { 
                 res.push_back(cur); 
                 return;
           }
        
        //if open is less
         if (open < max1)
            generate(res, cur+"(", open+1, close, max1);
        
        //if close is less
        if (close < open)
            generate(res, cur+")", open, close+1, max1); 
} 

vector<string> generateParenthesis(int n) 
{
        vector<string> res;
        generate(res,"",0,0,n);
        return res;
}
int main()
{
    int n=3;
    vector<string> paren= generateParenthesis(n);
    cout<<"[";
    for(int i=0;i<paren.size()-1;i++)
      cout<<paren[i]<<",";
    cout<<paren[paren.size()-1]<<"]";
   return 0;

}