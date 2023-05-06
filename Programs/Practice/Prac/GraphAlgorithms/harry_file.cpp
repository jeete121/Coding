#include <bits/stdc++.h>
using namespace std;

void harryFile(string s)
{
    int n = s.size();
    int i = n - 1;
    string ext = "";
    string file = "";
    while (i > 0)
    {
        while (i > 0 && s[i] != '.')
        {
            ext += s[i];
            i--;
        }
        i--;
        int x = s[i];
        while (i > 0 && x != 92)
        {
            file += s[i];
            i--;
            x = s[i];
        }

        break;
    }

    string path = "";
    for (int j = 0; j <= i; j++)
        path += s[j];
    cout << "Path: " << path << "\n";
    reverse(file.begin(), file.end());
    cout << "File name: " << file << "\n";
    reverse(ext.begin(), ext.end());
    cout << "Extension: " << ext << "\n";
}
int main()
{
    string s;
    cin >> s;

    harryFile(s);

    return 0;
}