#include <bits/stdc++.h>
using namespace std;


//function used as comparator in sorting
static bool cmp(string a, string b)
{
    int pos1 = a.find(' ');
    int pos2 = b.find(' ');
    if (a.substr(pos1 + 1) < b.substr(pos2 + 1))
        return true;
    if (a.substr(pos1 + 1) > b.substr(pos2 + 1))
        return false;
    else
        return a.substr(0, pos1 + 1) < b.substr(0, pos2 + 1);
}
vector<string> reorderLogFiles(vector<string> &logs)
{
    int n = logs.size();
    vector<string> v1, v2;
    for (auto i : logs)
    {
        if (isdigit(i[i.find(' ') + 1]))
            v2.push_back(i);
        else
            v1.push_back(i);
    }
    sort(v1.begin(), v1.end(), cmp);
    for (int i = 0; i < v2.size(); i++)
        v1.push_back(v2[i]);
    return v1;
}

int main()
{
    vector<string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6",
                           "let2 own kit dig", "let3 art zero"};

    vector<string> reorder = reorderLogFiles(logs);
    cout << "[";
    for (int i = 0; i < reorder.size() - 1; i++)
        cout << reorder[i] << ", ";
    cout << reorder[reorder.size() - 1] << "]";
    return 0;
}