#include <bits/stdc++.h>
using namespace std;

string delimiterReverse(string str,
                        vector<char> &delimiters)
{
    string res = "";
    queue<char> delimitersFound;
    stack<string> words = stack<string>();
    int lastIndex = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        for (int j = 0; j < delimiters.size(); ++j)
        {
            if (str[i] == delimiters[j])
            {
                delimitersFound.push(str[i]);
                words.push(str.substr(lastIndex, i - lastIndex));
                lastIndex = i + 1;
                break;
            }
        }
        if (i == (str.length() - 1) && (str[i] !=
                                        delimitersFound.front()))
        {
            words.push(str.substr(lastIndex, i - lastIndex + 1));
        }
    }
    while (!words.empty())
    {
        if (!words.empty())
        {
            res += words.top();
            words.pop();
        }
        if (!delimitersFound.empty())
        {

            res += delimitersFound.front();
            delimitersFound.pop();
        }
    }
    return res;
}

int main()

{

    string str = "hello/world:here";

    vector<char> delimiters = {':', '/'};
    cout << delimiterReverse(str, delimiters);

    return 0;
}