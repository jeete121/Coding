#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<string> &logs)
{
    int cnt = 0;
    for (int i = 0; i < logs.size(); i++)
    {
        if (logs[i] == "../")
        {
            if (cnt > 0)
                cnt--;
        }
        else if (logs[i] == "./")
            continue;
        else
            cnt++;
    }
    return cnt;
}

int main()
{
    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
    cout << minOperations(logs);
    return 0;
}