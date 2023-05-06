#include <bits/stdc++.h>
using namespace std;

vector<int> l;
//Get the value of the index-th node in the linked list.
//If the index is invalid, return -1.
int get(int index)
{
    if (index < l.size())
        return l[index];
    else
        return -1;
}

//Add a node of value val before the first element of
//the linked list. After the insertion, the new node will
// be the first node of the linked list.
void addAtHead(int val)
{
    l.insert(l.begin(), val);
}

//Append a node of value val to the last element of the linked list.

void addAtTail(int val)
{
    l.push_back(val);
}

//function to Add a node of value val before the index-th
//node in the linked list. If index equals to the length of
//linked list, the node will be appended to the end of linked list.
// If index is greater than the length, the node will not be inserted.
void addAtIndex(int index, int val)
{
    if (index < 0)
        addAtHead(val);
    else if (index <= l.size())
        l.insert(l.begin() + index, val);
}

//function to Delete the index-th node in the linked list,
//if the index is valid
void deleteAtIndex(int index)
{
    if (index < l.size())
        l.erase(l.begin() + index);
}
int main()
{
    cout << "Get Element " << get(0) << "\n";
    cout << "Add Element at head\n";
    addAtHead(2);
    cout << "Get Element " << get(0) << "\n";
    cout << "Add Element at tail\n";
    addAtTail(3);
    cout << "Get Element " << get(1) << "\n";
    deleteAtIndex(1);
    cout << "Get Element " << get(1) << "\n";
}