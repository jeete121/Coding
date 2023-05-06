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
char deepesTreeNode(TreeNode *tree)
{

    queue<TreeNode *> q;
    TreeNode *temp = tree;
    TreeNode *prev = tree;
    while (temp != NULL)
    {
        prev = temp;
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        temp = q.front();
        q.pop();
    }
    return prev->data;
}

int main()
{
    TreeNode *root = new TreeNode('a');
    root->left = new TreeNode('b');
    root->right = new TreeNode('c');
    root->left->left = new TreeNode('d');

    cout << deepesTreeNode(root);

    return 0;
}