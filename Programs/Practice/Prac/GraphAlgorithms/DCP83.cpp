#include <bits/stdc++.h>
using namespace std;
//struct for treenode
struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void invert(TreeNode *root)
{
    if (root == NULL)
        return;
    else
    {
        invert(root->left);
        invert(root->right);
        TreeNode *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
TreeNode *invertTree(TreeNode *root)
{
    invert(root);
    return root;
}
//function to print the tree
void printTree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    vector<string> vec;
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        if (root == NULL)
            vec.push_back("null");
        else
            vec.push_back(to_string(root->data));
        if (root != NULL)
        {
            q.push(root->left);
            q.push(root->right);
        }
    }
    int j = vec.size() - 1;
    while (j > 0 && vec[j] == "null")
        j--;
    vec.resize(j);
    for (int i = 0; i < j; i++)
    {
        if (vec[i] != "null")

            cout << (char)stoi(vec[i]) << ",";
        else
            cout << vec[i] << ",";
    }
    cout << (char)stoi(vec[j]);
}
int main()
{

    TreeNode *root = new TreeNode('a');
    root->left = new TreeNode('b');
    root->right = new TreeNode('c');
    root->left->left = new TreeNode('d');
    root->left->right = new TreeNode('e');
    root->right->left = new TreeNode('f');

    root = invertTree(root);
    printTree(root);
    return 0;
}