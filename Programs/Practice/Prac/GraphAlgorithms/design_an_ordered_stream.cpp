#include <bits/stdc++.h>
using namespace std;

class OrderedStream
{
private:
    int id = 1;

    unordered_map<int, string> m;

public:
    OrderedStream(int n)
    {
    }

    vector<string> insert(int idKey, string value)
    {
        m[idKey] = value;
        vector<string> res;

        while (m.find(id) != m.end())
        {
            res.emplace_back(m[id]);
            id++;
        }

        return res;
    }
};

int main()
{

    OrderedStream os(5);
    vector<string> res = os.insert(3, "ccccc");
    cout << "[";
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "], ";
    res = os.insert(1, "aaaaa");
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "], ";
    res = os.insert(2, "bbbbb");
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "], ";
    res = os.insert(5, "eeeee");
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "], ";
    res = os.insert(4, "ddddd");
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";
    cout << "]";
    return 0;
}
