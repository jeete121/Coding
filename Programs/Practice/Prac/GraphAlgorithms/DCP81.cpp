#include <bits/stdc++.h>
using namespace std;

vector<string> combinFunc(vector<string> svec1, string inString)
{
    vector<string> s1 = {};
    if (svec1.empty())
    {
        for (int i = 0; i < inString.size(); ++i)
        {
            s1.push_back(inString.substr(i, 1));
        }
        return s1;
    }
    for (int i = 0; i < svec1.size(); ++i)
    {
        for (int j = 0; j < inString.size(); ++j)
        {
            s1.push_back(svec1[i] + inString[j]);
        }
    }
    return s1;
}
vector<string> letterCombinations(string digits)
{
    map<char, string> myMap = {{'2', "abc"},
                               {'3', "def"},
                               {'4', "ghi"},
                               {'5', "jkl"},
                               {'6', "mno"},
                               {'7', "pqrs"},
                               {'8', "tuv"},
                               {'9', "wxyz"}};
    if (digits.empty())
        return {};
    vector<string> svec;
    for (int i = 0; i < digits.size(); ++i)
    {
        svec.push_back(myMap[digits[i]]);
    }
    vector<string> sol = {};
    for (int i = 0; i < svec.size(); ++i)
    {
        sol = combinFunc(sol, svec[i]);
    }
    return sol;
}



int main()
{
    string digits = "23";

    vector<string> res = letterCombinations(digits);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}