#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    int cap;
    vector<int> v;
    unordered_map<int, int> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        auto pos = find(v.begin(), v.end(), key);
        if (pos != v.end())
        {
            v.erase(pos);
            v.push_back(key);
            return mp[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto pos = find(v.begin(), v.end(), key);
        if (pos != v.end())
            v.erase(pos);

        if (v.size() == cap)
        {
            mp[v[0]] = 0;
            v.erase(v.begin());
        }

        mp[key] = value;
        v.push_back(key);
    }
};

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    cout << "[";
    cout << lRUCache.get(1) << ", ";
    lRUCache.put(3, 3);
    cout << lRUCache.get(2) << ", ";
    lRUCache.put(4, 4);
    cout << lRUCache.get(1) << ", ";
    cout << lRUCache.get(3) << ", ";
    cout << lRUCache.get(4);
    cout << "]";

    return 0;
}