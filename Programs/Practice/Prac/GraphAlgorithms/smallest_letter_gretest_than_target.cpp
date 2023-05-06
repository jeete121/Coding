#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char t) 
{
     
        int low=0,high=letters.size()-1;
        char ans='#';
        while(low<=high)
        {
           int mid=low+(high-low)/2;
           if(letters[mid]>t)
           {
               high=mid-1;
               ans=letters[mid];
           }
          else
              low=mid+1;
        }
        if(ans=='#')
              return letters[0];
        return ans;
}

int main()
{
    vector<char> letters={'c','f','j'};
    char target='a';
    cout<<nextGreatestLetter(letters,target);
    return 0;
}