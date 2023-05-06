#include <bits/stdc++.h>
using namespace std;

int findVaccines(int n, int m, string s, vector<string> &str, vector<int> &x)
{
    long long max1 = 0;
    long long ans = 0, c = 0, g = 0;
    for (long long i = 0; i < m; i++)
    {
        if (s[i] == 'C')
            c++;
        else if (s[i] == 'G')
            g++;
    }
    for (long long i = 0; i < n; i++)
    {

        long long cnt = 0;
        for (long long j = 0; j < x[i]; j++)
        {
            if (str[i][j] == 'C')
                cnt += g;
            else if (str[i][j] == 'G')
                cnt += c;
        }
        if (cnt > max1)
        {
            ans = i + 1;
            max1 = cnt;
        }
    }
    return ans;
}
int main()
{

    long long n = 2, m = 5;
    string s = "ACGGU";
    vector<int> value = {6, 8};
    vector<string> vaccines = {"AGCAAA", "UAUAAGAG"};
    cout << findVaccines(n, m, s, vaccines, value);

    return 0;
}