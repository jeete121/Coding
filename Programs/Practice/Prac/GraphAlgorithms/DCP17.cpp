#include <bits/stdc++.h>
using namespace std;

int lengthLongestPath(string input)
{
    stringstream ss(input);
    string line;
    unordered_map<int, int> map = {{0, 0}};
    int res = 0;

    while (getline(ss, line, '\n'))
    {
        auto tab = line.find_last_of('\t');
        int level = tab == string::npos ? 0 : tab + 1;
        int len = line.substr(level).length();
        if (line.find('.') != string::npos)
        {
            res = max(res, map[level] + len);
        }
        else
        {
            map[level + 1] = map[level] + len + 1;
        }
    }
    return res;
}

int main()
{
    string input = "file1.txt\nfile2.txt\nlongfile.txt";

    cout << lengthLongestPath(input);

    return 0;
}