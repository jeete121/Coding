#include <bits/stdc++.h>
using namespace std;

string getResult(string a)
{
    bool lovely = true, loop = true;

    while (loop)
    {
        if (a.find("a") != string::npos || a.find("A") != string::npos)
        {
        }
        else
        {
            lovely = false;
            break;
        }
        if (a.find("e") != string::npos || a.find("E") != string::npos)
        {
        }
        else
        {
            lovely = false;
            break;
        }
        if (a.find("i") != string::npos || a.find("I") != string::npos)
        {
        }
        else
        {
            lovely = false;
            break;
        }
        if (a.find("o") != string::npos || a.find("O") != string::npos)
        {
        }
        else
        {
            lovely = false;
            break;
        }
        if (a.find("u") != string::npos || a.find("U") != string::npos)
        {
        }
        else
        {
            lovely = false;
            break;
        }
        break;
    }

    if (lovely)
    {
        return "lovely string";
    }
    else
    {
        return "ugly string";
    }
}

int main()
{

    string str = "omahgoTuRuLob";

    cout << getResult(str) << "\n";

    return 0;
}
