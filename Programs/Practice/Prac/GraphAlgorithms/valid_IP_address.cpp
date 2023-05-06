#include <bits/stdc++.h>
using namespace std;

string validIPAddress(string IP)
{
    stringstream s(IP);
    string temp;
    int cnt = 0;
    if (IP.find(":") == string ::npos)
    {
        while (getline(s, temp, '.'))
        {
            cnt++;
            if (cnt > 4 || temp.size() > 3 || temp.size() == 0 || (temp.size() > 1 && temp[0] == '0'))
                return "Neither";
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] > '9' || temp[i] < '0')
                    return "Neither";
                int x = stoi(temp);
                if (x > 255 || x < 0)
                    return "Neither";
            }
        }
        return (cnt == 4 && IP.back() != '.') ? "IPv4" : "Neither";
    }
    else
    {
        while (getline(s, temp, ':'))
        {
            cnt++;
            if (cnt > 8 || temp.size() == 0 || temp.size() > 4)
                return "Neither";
            for (int i = 0; i < temp.size(); i++)
            {
                if (!(temp[i] >= '0' && temp[i] <= '9') &&
                    !(temp[i] >= 'a' && temp[i] <= 'f') && !(temp[i] >= 'A' && temp[i] <= 'F'))
                    return "Neither";
            }
        }
        return (cnt == 8 && IP.back() != ':') ? "IPv6" : "Neither";
    }
}

int main()
{
    string IP = "172.16.254.1";
    cout << validIPAddress(IP);
    return 0;
}