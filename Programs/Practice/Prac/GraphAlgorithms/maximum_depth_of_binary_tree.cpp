#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {

        int len = q.size();
        while (len--)
        {
            root = q.front();
            q.pop();
            for (auto it : root->children)
            {
                q.push(it);
            }
        }
        level++;
    }
    return level;
}

int main()
{
    Node *root=new Node(1);
    
    vector<Node *> child1;

}