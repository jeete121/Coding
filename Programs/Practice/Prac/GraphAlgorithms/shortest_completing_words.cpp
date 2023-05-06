#include <bits/stdc++.h>
using namespace std;

string shortestCompletingWord(string licensePlate,
                              vector<string> &words)
{
    string res = "";
    int mp[26] = {0};
    for (int i = 0; i < licensePlate.size(); i++)
    {
        if (licensePlate[i] >= 'a' && licensePlate[i] <= 'z')
        {
            mp[licensePlate[i] - 'a']++;
        }
        else if (licensePlate[i] >= 'A' && licensePlate[i] <= 'Z')
        {
            mp[licensePlate[i] + 32 - 'a']++;
        }
    }
    int len = INT_MAX;
    for (int i = 0; i < words.size(); i++)
    {
        int mp1[26] = {0};
        int flag = 0;

        for (int j = 0; j < words[i].size(); j++)
        {
            mp1[words[i][j] - 'a']++;
        }

        for (int j = 0; j < 26; j++)
        {
            if (mp1[j] < mp[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            if (len > words[i].size())
            {
                len = words[i].size();
                res = words[i];
            }
        }
    }
    return res;
}

int main()
{
    string licensePlate = "1s3 PSt";
    vector<string> words = {"step", "steps", "stripe", "stepple"};

    cout << shortestCompletingWord(licensePlate, words);

    return 0;
}