#include <bits/stdc++.h>
using namespace std;


//function to check for unique occurrences
bool uniqueOccurrences(vector<int>& arr) 
{
    map<int,int> mp;
    for(int i=0;i<arr.size();i++)
         mp[arr[i]]++;
    bool flag=true;
    set<int> st;
    for(int i=0;i<arr.size();i++)
     {
        if(mp[arr[i]]>0&&st.find(mp[arr[i]])!=st.end())
            {
                flag=false;
                break;
            }

            st.insert(mp[arr[i]]);
            mp[arr[i]]=0;
    }
     return flag;
}
int main()
{
    vector<int> arr ={1,2,2,1,1,3};
    if(uniqueOccurrences(arr))
       cout<<"true\n";
    else
      cout<<"false\n";
    return 0;
}

