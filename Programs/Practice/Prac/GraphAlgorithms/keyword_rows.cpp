#include <bits/stdc++.h>
using namespace std;

vector<string> findWords(vector<string> &words)
{
    set<char> st1, st2, st3;
    st1.insert('Q');
    st1.insert('W');
    st1.insert('E');
    st1.insert('R');
    st1.insert('T');
    st1.insert('Y');
    st1.insert('U');
    st1.insert('I');
    st1.insert('O');
    st1.insert('P');

    st1.insert('q');
    st1.insert('w');
    st1.insert('e');
    st1.insert('r');
    st1.insert('t');
    st1.insert('y');
    st1.insert('u');
    st1.insert('i');
    st1.insert('o');
    st1.insert('p');

    st2.insert('A');
    st2.insert('S');
    st2.insert('D');
    st2.insert('F');
    st2.insert('G');
    st2.insert('H');
    st2.insert('J');
    st2.insert('K');
    st2.insert('L');

    st2.insert('a');
    st2.insert('s');
    st2.insert('d');
    st2.insert('f');
    st2.insert('g');
    st2.insert('h');
    st2.insert('j');
    st2.insert('k');
    st2.insert('l');

    st3.insert('Z');
    st3.insert('X');
    st3.insert('C');
    st3.insert('V');
    st3.insert('B');
    st3.insert('N');
    st3.insert('M');

    st3.insert('z');
    st3.insert('x');
    st3.insert('c');
    st3.insert('v');
    st3.insert('b');
    st3.insert('n');
    st3.insert('m');
    vector<string> res;
    for (int i = 0; i < words.size(); i++)
    {
        bool one = false, two = false, three = false;
        for (int j = 0; j < words[i].size(); j++)
        {
            if (st1.find(words[i][j]) != st1.end())
                one = true;
            else if (st2.find(words[i][j]) != st2.end())
                two = true;
            else
                three = true;
        }
        if (one == true && two == false && three == false)
            res.push_back(words[i]);
        else if (one == false && two == true && three == false)
            res.push_back(words[i]);
        else if (one == false && two == false && three == true)
            res.push_back(words[i]);
    }
    return res;
}

int main()
{
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};

    vector<string> res = findWords(words);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}