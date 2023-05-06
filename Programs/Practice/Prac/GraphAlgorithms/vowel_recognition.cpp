#include <bits/stdc++.h>
using namespace std;
bool isvowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

void vowelRecognition(string str)
{
    for (long long int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    long long int arr[str.size()];
    for (long long int i = 0; i < str.size(); i++)
    {
        if (isvowel(str[i]))
            arr[i] = 1;
        else
            arr[i] = 0;
    }

    long long int cnt = 0;

    for (long long int i = 1; i < str.size(); i++)
        arr[i] = arr[i] + arr[i - 1];

    long long int suffix[str.size()];
    for (long long int i = 0; i < str.size(); i++)
        suffix[i] = 0;
    suffix[str.size() - 1] = arr[str.size() - 1];
    for (long long int i = str.size() - 2; i >= 0; i--)
        suffix[i] = arr[i] + suffix[i + 1];

    cnt += suffix[0];
    for (long long int i = 1; i < str.size(); i++)
    {
        if (suffix[i] == suffix[i - 1])
            cnt += suffix[i];
        else
        {
            long long int diff = suffix[i - 1] - suffix[i];
            cnt += suffix[i] - diff * (str.size() - i);
        }
    }
    cout << cnt << "\n";
}
int main()
{

    string str = "baceb";

    vowelRecognition(str);

    return 0;
}