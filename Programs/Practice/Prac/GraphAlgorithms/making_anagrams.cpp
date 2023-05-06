#include <bits/stdc++.h>
using namespace std;

int makingAnagrams(string s1, string s2)
{
    int f1[26] = {0};
    for (int i = 0; i < s1.size(); i++)
    {
        f1[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        f1[s2[i] - 'a']--;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++)
    {
        sum += abs(f1[i]);
    }
    return sum;
}

int main()
{

    string s1 = "cde";
    string s2 = "abc";

    int result = makingAnagrams(s1, s2);
    cout << result << "\n";

    return 0;
}
