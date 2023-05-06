#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    char val;
    TreeNode *left, *right;

    TreeNode(char ch)
    {
        this->val = ch;
        this->left = NULL;
        this->right = NULL;
    }
};
int evaluate(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (isdigit(root->val))
        return root->val - '0';

    //if + sign
    if (root->val == '+')
        return evaluate(root->left) + evaluate(root->right);

    //if - sign
    if (root->val == '-')
        return evaluate(root->left) - evaluate(root->right);

    //if * sign
    if (root->val == '*')
        return evaluate(root->left) * evaluate(root->right);

    //if / sign

    return evaluate(root->left) / evaluate(root->right);
}

int main()
{
    TreeNode *root = new TreeNode('*');
    root->left = new TreeNode('+');
    root->right = new TreeNode('+');

    root->left->left = new TreeNode('3');
    root->left->right = new TreeNode('2');

    root->right->left = new TreeNode('4');
    root->right->right = new TreeNode('5');

    cout << evaluate(root);

    return 0;
}