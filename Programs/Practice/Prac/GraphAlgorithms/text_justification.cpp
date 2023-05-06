#include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxW)
{
    int space = 0;
    vector<string> ans;
    map<string, int> mp;
    for (int i = 0; i < words.size(); i++)
        mp[words[i]] = words[i].size();

    int sum = 0, start = 0;
    for (int i = 0; i < words.size(); i++)
    {
        sum += mp[words[i]];
        if (sum + space > maxW)
        {
            string tmp = "";

            int div = i - start - 1;
            int rem = maxW - (sum - mp[words[i]]);
            int extra = (div == 0) ? rem : rem % div;
            for (int j = start; j < i; j++)
            {
                tmp += words[j];
                if (j == i - 1)
                    continue;
                for (int k = 0; k < rem / div; k++)
                    tmp += " ";
                if (extra > 0)
                {
                    tmp += " ";
                    extra--;
                }
            }
            if (div == 0)
            {
                while (rem--)
                    tmp += " ";
            }
            ans.push_back(tmp);
            space = 0;
            sum = mp[words[i]];
            start = i;
        }
        space++;
    }
    string tmp = "";
    sum = 0;
    for (int j = start; j < words.size() - 1; j++)
    {
        tmp += words[j];
        tmp += " ";
        sum += mp[words[j]] + 1;
    }
    tmp += words[words.size() - 1];
    sum += mp[words[words.size() - 1]];
    while (sum < maxW)
    {
        tmp += " ";
        sum++;
    }
    ans.push_back(tmp);
    return ans;
}
int main()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    vector<string> res = fullJustify(words, maxWidth);

    cout << "[\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",\n";
    }
    cout << "\n";
    cout << "]";

    return 0;
}