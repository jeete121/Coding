#include <bits/stdc++.h>
using namespace std;

int nextGreaterElement(int n)
{
    string str = to_string(n);
    long long int i = 1;
    long long int m = str.size();
    while (i < m && str[i] <= str[i - 1])
        i++;
    if (i == m)
        return -1;
    long long int j = m - 1;
    long long int ind = j - 1;

    while (j > 0 && str[j - 1] >= str[j])
    {
        j--;
    }
    long long int min1 = str[j - 1];
    long long int f = 0;
    long long int max1 = str[j - 1];
    vector<pair<int, int>> v;
    for (int i = j; i < m; i++)
    {
        if (str[i] > max1 && str[i] != min1)
        {

            v.push_back({str[i], i});
            ind = i;
            f = 1;
        }
    }
    sort(v.begin(), v.end());
    if (f == 0)
        swap(str[j], str[ind]);
    else
        swap(str[j - 1], str[v[0].second]);
    string p = str.substr(0, j);
    string x = str.substr(j);
    sort(x.begin(), x.end());
    str = "";
    str = p + x;

   //convert string to integer
    stringstream strr(str);
    long long int num=0;
    strr>>num;
    if (num >= 2147483648)
        return -1;
    return num;
}

int main()
{
    int n = 12;
    cout << nextGreaterElement(n);
    return 0;
}