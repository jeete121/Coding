#include <bits/stdc++.h>
using namespace std;

class HashSetOwn {
    vector<int> map;

   public:
    HashSetOwn() {
        map.clear();
        map.resize(1000000,-1);

    }

    void add(int key) {
        map[key] =1;
    }

    bool contains(int key) {
        if (map[key] != -1)
            return true;
        return false;

    }

    void remove(int key) {
        map[key] = -1;
    }

};
int main()
{
   HashSetOwn set;
   cout<<"add(1) : "<<"\n";
   set.add(1);
   cout<<"add(2) : "<<"\n";
   set.add(2);
   cout<<"contains(1): "<<set.contains(1)<<"\n";
   set.remove(1);
   cout<<"contains(1): "<<set.contains(1)<<"\n";
   cout<<"add(1) : "<<"\n";;
   set.add(1);
   return 0;
}
