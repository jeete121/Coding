#include <bits/stdc++.h>
using namespace std;

string longestWord(vector<string> &words)
{
    sort(words.begin(), words.end());
    string result = "";
    set<string> builtWords;
    for (auto w : words)
    {
        //if current words length is 1 or
        //current words is found in the set
        if (w.length() == 1 ||
            builtWords.find(w.substr(0, w.length() - 1)) != builtWords.end())
        {
            //if length of current word is more then
            //the length of result then
            //update result
            if (w.length() > result.length())
            {
                result = w;
            }

            //insert current word into the set
            builtWords.insert(w);
        }
    }
    return result;
}

int main()
{
    vector<string> words = {"w", "wo", "wor", "worl", "world"};

    cout << longestWord(words);

    return 0;
}