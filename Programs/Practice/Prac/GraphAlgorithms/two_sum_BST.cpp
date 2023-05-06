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
vector<int> v;
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    //call for left subtree
    inorder(root->left);

    //data
    v.push_back(root->data);

    //right subtree
    inorder(root->right);
}
bool findTarget(TreeNode *root, int k)
{
    inorder(root);
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        if (v[i] + v[j] == k)
            return true;
        else if (v[i] + v[j] > k)
            j--;
        else
            i++;
    }
    return false;
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    int k = 4;
    if (findTarget(root, k))
        cout << "true";
    else
        cout << "false";
    return 0;
}