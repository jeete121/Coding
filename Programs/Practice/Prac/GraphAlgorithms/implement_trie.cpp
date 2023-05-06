#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char val = '\0';
    struct Node *child[26];
    bool isword = false;
};
Node *root = new Node();

//funtion to insert word
//into the trie
void insert(string word)
{
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
        char c = word[i];
        int index = c - 'a';
        if (node->child[index])
        {
            node = node->child[index];
            continue;
        }
        node->child[index] = new Node();
        node->child[index]->val = c;
        node = node->child[index];
    }
    node->isword = true;
}

//check if word is present in the
//trie
bool search(string word)
{
    struct Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
        char c = word[i];
        int index = c - 'a';
        if (!node->child[index])
            return false;
        node = node->child[index];
    }
    if (node->isword)
        return true;
    return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool startsWith(string prefix)
{
    Node *node = root;
    for (int i = 0; i < prefix.size(); i++)
    {
        char c = prefix[i];
        int index = c - 'a';
        if (!node->child[index])
            return false;
        node = node->child[index];
    }
    return true;
}

int main()
{

    cout << "[";
    insert("apple");
    if (search("apple"))
        cout << "true, ";
    else
        cout << "false, ";
    if (search("app"))
        cout << "true, ";
    else
        cout << "false, ";
    if (startsWith("app"))
        cout << "true, ";
    else
        cout << "false, ";
    insert("app");
    if (search("app"))
        cout << "true";
    else
        cout << "false";

    cout << "]";

    return 0;
}