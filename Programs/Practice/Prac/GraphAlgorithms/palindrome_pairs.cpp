#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string &a,string &b)
{
        
        int low=0,high=b.size()-1;

        //check for palindrome in string
        // a+b
        while(low<a.size()&&high>=0)
        {
            if(a[low]!=b[high])
                  return false;
            low++;
            high--;
        }
        if(low==a.size()&&high>=0)
        {
            low=0;
            while(low<high)
            {
                if(b[low]!=b[high])
                      return false;
                low++;
                high--;
            }
            
        }
        if(low<a.size()&&high<0)
        {
            high=a.size()-1;
            while(low<high)
            {
                if(a[low]!=a[high])
                      return false;
                low++;
                high--;
            }
        }
        return true;
}

//function to find all the palindrome pairs
vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(isPalindrome(words[i],words[j]))
                      res.push_back({i,j});
                if(isPalindrome(words[j],words[i]))
                        res.push_back({j,i});
            }
        }
        return res;
}
int main()
{
   vector<string> words={"abcd","dcba","lls","s","sssll"};
   vector<vector<int> > pair=palindromePairs(words);
   cout<<"[";
   for(int i=0;i<pair.size();i++)
      {
          cout<<"[";
          cout<<pair[i][0]<<","<<pair[i][1]<<" ";
           if(i!=pair.size()-1)
              cout<<"],";
        else
          cout<<"]";
      }
      cout<<"]";
   return 0;

}
