#include <bits/stdc++.h>
using namespace std;
//struct for treenode
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

string tree2str(TreeNode *t)
{
    if (t == NULL)
        return "";
    string str = to_string(t->data);
    if (t->left)
    {
        str += "(" + tree2str(t->left) + ")";
    }
    else if (t->right)
        str += "()";
    if (t->right)
        str += "(" + tree2str(t->right) + ")";
    return str;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    cout << tree2str(root);

    return 0;
}