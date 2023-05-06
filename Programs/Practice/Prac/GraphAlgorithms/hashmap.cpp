#include <bits/stdc++.h>
using namespace std;
vector<int> hashMap;

//function to add the value
//at the given key
void put(int key, int value) 
{
     hashMap[key]=value;
 
}

//get the value at given 
//key
int get(int key) 
{
    return hashMap[key];  
}

//remove the element from
//the hashMap
void remove(int key) 
{
        hashMap[key]=-1;
}
int main()
{ 
    hashMap.clear();
    hashMap.resize(1000001,-1);
    put(1,1);
    put(1,2);
    cout<<get(1)<<"\n";
    put(2,3);
    cout<<get(2)<<"\n";
    remove(1);
    return 0;

}
