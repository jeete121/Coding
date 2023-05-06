#include <bits/stdc++.h>
using namespace std;

int strongPasswordChecker(string password)
{

    int cnt[3] = {0};

    // inserstions only
    if (password.size() <= 3)
    {
        return 6 - password.size();
    }

    for (int i = 0; i < password.size(); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            cnt[0] = 1;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            cnt[1] = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            cnt[2] = 1;
    }

    int missing = 3 - (cnt[0] + cnt[1] + cnt[2]);

    if (password.size() == 4)
    {
        // one replacement and two insertions
        if (missing == 3)
            return 3;
        // two insertions
        else
            return 2;
    }
    else if (password.size() == 5)
    {
        // two replacement, and one insertion
        if (missing == 3)
            return 3;
        // one replacement, and one insertion
        else if (missing == 2)
            return 2;
        // one insertion;
        else if (missing == 1)
            return 1;
        // one insertion
        else
            return 1;
    }
    else if (password.size() >= 6 && password.size() <= 20)
    {
        int i = 1;
        int replacements = 0;
        while (i < password.size())
        {
            if (password[i] == password[i - 1])
            {
                int j = i - 1;
                while (i < password.size() && password[i] == password[i - 1])
                    i++;
                replacements += (i - j) / 3;
            }
            else
            {
                i++;
            }
        }
        return max(replacements, missing);
    }
    else
    {
        // password.size() > 20
        int extra_cnt = password.size() - 20;
        int i = 1;
        int replacements = 0;
        int deleted = 0;
        vector<int> size_seq;
        while (i < password.size())
        {
            if (password[i] == password[i - 1])
            {
                int j = i - 1;
                while (i < password.size() && password[i] == password[i - 1])
                    i++;
                int size = i - j;
                if ((size % 3) == 0 && extra_cnt)
                {
                    size--;
                    deleted++;
                    extra_cnt--;
                }
                if (size >= 3)
                {
                    size_seq.push_back(size);
                }
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < size_seq.size() && extra_cnt >= 2; i++)
        {
            if (size_seq[i] > 3 && (size_seq[i] % 3) == 1)
            {
                deleted += 2;
                extra_cnt -= 2;
                size_seq[i] -= 2;
            }
        }

        for (int i = 0; i < size_seq.size(); i++)
        {
            while (size_seq[i] >= 3 && extra_cnt >= 3)
            {
                deleted += 3;
                extra_cnt -= 3;
                size_seq[i] -= 3;
            }
            replacements += size_seq[i] / 3;
        }
        return deleted + extra_cnt + max(replacements, missing);
    }
}

int main()
{
    string password = "aA1";

    cout << strongPasswordChecker(password);

    return 0;
}