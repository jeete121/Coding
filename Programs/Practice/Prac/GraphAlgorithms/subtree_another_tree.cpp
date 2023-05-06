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

bool isIdentical(TreeNode *s, TreeNode *t)
{
    if (s == NULL && t == NULL)
        return true;
    if (s == NULL || t == NULL)
        return false;
    return (s->data == t->data && isIdentical(s->left, t->left) && isIdentical(s->right, t->right));
}
bool isSubtree(TreeNode *s, TreeNode *t)
{
    if (t == NULL)
        return true;
    if (s == NULL)
        return false;
    if (isIdentical(s, t))
        return true;
    //call for left subtree and right subtree
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main()
{

    TreeNode *s = new TreeNode(3);
    s->left = new TreeNode(4);
    s->right = new TreeNode(5);
    s->left->left = new TreeNode(1);
    s->left->right = new TreeNode(2);

    TreeNode *t = new TreeNode(4);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);

    if (isSubtree(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}
