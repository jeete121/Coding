#include <bits/stdc++.h>
using namespace std;

bool isSameAfterShifting(string str1, string str2)
{
    // check if the strings are empty
    //or has different lengths
    if (str1.size() == 0 || str2.size() == 0 ||
        str1.size() != str2.size())
        return false;

    // check if the strings are the same
    if (str1 == str2)
        return true;

    // generate the array
    vector<string> arr;
    for (int i = 0; i < str1.size(); i++)
    {
        string c = str1.substr(i) + str1.substr(0, i);
        arr.push_back(c);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == str2)
            return true;
    }
    return false;
}
int main()
{
    string str1 = "abcde";
    string str2 = "cdeab";
    if (isSameAfterShifting(str1, str2))
        cout << "true";
    else
        cout << "false";

    return 0;
}