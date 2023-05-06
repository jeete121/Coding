#include <bits/stdc++.h>
using namespace std;


//function to check for the
//character is vowel or not
bool isvowel(char c)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
string toGoatLatin(string S)
{
    string str = "";
    string x = "";
    int i = 0;
    int cnt = 1;
    int n = S.size();
    while (i < n)
    {
        string str1 = "";
        while (i < n && S[i] == ' ')
            i++;
        while (i < n && S[i] != ' ')
        {
            str1 += S[i];
            i++;
        }
        if (isvowel(str1[0]))
        {
            str += str1;
            str += "ma";
            for (int j = 1; j <= cnt; j++)
                str += "a";
            if (i != n)
                str += " ";
        }
        else
        {
            for (int j = 1; j < str1.size(); j++)
                str += str1[j];
            str += str1[0];
            str += "ma";
            for (int j = 1; j <= cnt; j++)
                str += "a";
            if (i != n)
                str += " ";
        }
        cnt++;
    }
    return str;
}

int main()
{
    string str = "I speak Goat Latin";
    cout << toGoatLatin(str);
    return 0;
}