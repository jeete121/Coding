#include <bits/stdc++.h>
using namespace std;


//function to check if string
//is palindrome or not
bool isPalindrome(string s)
{
    int low=0;
    int high=s.size()-1;
    while(low<high)
        {
            if(s[low]!=s[high])
                  return false;
            low++;
            high--;
        }
    return true;
}

//partitions the strings
void partitions(string s,vector<vector<string>>&res,vector<string> &partial)
{
        //base case
        //if there is nothing left then push the partial ans to the main ans(res)
        if(s.size()==0)
            res.push_back(partial);
     
        else
        {
            //check for all substring for palindrome
            for(int i=0;i<s.size();i++)
            {
                string left=s.substr(0,i+1);
                string right=s.substr(i+1);
                if(isPalindrome(left))
                {
                    //push the current palindrome into partial ans
                    partial.push_back(left);
                    //recurr for right part
                    partitions(right,res,partial);
                    //backtracking
                    partial.pop_back();
                }
            
            }
       }
}
vector<vector<string>> partition(string s) 
{
        vector<vector<string>> res;
        vector<string> partial;
        partitions(s,res,partial);
        return res;
}

int main()
{
    string str="aab";
    vector<vector<string>> part=partition(str);

    cout<<"[";
    for(int i=0;i<part.size();i++)
      {
          cout<<"[";
          for(int j=0;j<part[i].size();j++)
             {
                cout<<part[i][j];
                if(j!=part[i].size()-1)
                  cout<<",";
             }
            cout<<"]";
            if(i!=part.size()-1)
              cout<<",";
      }
     cout<<"]";
    return 0;
}