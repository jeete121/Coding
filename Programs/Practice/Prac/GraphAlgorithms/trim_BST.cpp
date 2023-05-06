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

TreeNode *trimBST(TreeNode *root, int L, int R)
{
    if (root == NULL)
        return root;

    //if root data is greater than R than cal for left subtree
    if (root->data > R)
        return trimBST(root->left, L, R);

    //if root data is less than L than call for right subtree
    if (root->data < L)
        return trimBST(root->right, L, R);

    //call for left subtree
    root->left = trimBST(root->left, L, R);

    //call for right subtree
    root->right = trimBST(root->right, L, R);
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
    cout << "[";
    for (int i = 0; i < j; i++)
        cout << vec[i] << ",";
    cout << vec[j] << "]";
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    int low = 1, high = 2;

    TreeNode *tree = trimBST(root, low, high);

    printTree(tree);

    return 0;
}