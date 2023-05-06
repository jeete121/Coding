#include <bits/stdc++.h>

using namespace std;

int minimumNumber(int n, string password)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            cnt2++;
        if (password[i] >= 'a' && password[i] <= 'z')
            cnt1++;
        if (password[i] >= '0' && password[i] <= '9')
            cnt0++;
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+')
            cnt3++;
    }

    int sum = 0;
    if (cnt0 == 0)
        sum += 1;
    if (cnt1 == 0)
        sum += 1;
    if (cnt2 == 0)
        sum += 1;
    if (cnt3 == 0)
        sum += 1;
    if (sum + password.size() < 6)
        return 6 - password.size();
    return sum;
}

int main()
{
    int n = 3;
    string password = "Ab1";

    int answer = minimumNumber(n, password);
    cout << answer << "\n";

    return 0;
}
