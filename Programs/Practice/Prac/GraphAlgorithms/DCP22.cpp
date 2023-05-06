#include <bits/stdc++.h>
using namespace std;

void wordBreakString(vector<string> &dict,
                     string str, vector<string> &res)
{

    if (str.size() == 0)
    {
        return;
    }

    for (int i = 1; i <= str.size(); i++)
    {

        string prefix = str.substr(0, i);

        if (find(dict.begin(), dict.end(), prefix) != dict.end())
        {
            res.push_back(prefix);
            wordBreakString(dict, str.substr(i), res);
        }
    }
}

int main()
{

    vector<string> dict = {"quick", "brown", "the", "fox"};

    string str = "thequickbrownfox";

    vector<string> res;
    wordBreakString(dict, str, res);

    cout<<"[";
    for(int i=0;i<res.size();i++)
     {
         cout<<res[i];
         if(i!=res.size()-1)
           cout<<", ";
     }
     cout<<"]";
    return 0;
}
