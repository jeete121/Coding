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
int largestBST(TreeNode *root, int &min, int &max,
    int &size, TreeNode *&bstRoot)
{
    if (root == NULL)
        return 0;

    int leftMin = INT_MIN, rightMin = INT_MIN;
    int leftMax = INT_MAX, rightMax = INT_MAX;
    int x, y;

    x = largestBST(root->left, leftMin, leftMax, size, bstRoot);
    y = largestBST(root->right, rightMin, rightMax, size, bstRoot);

    if (x == -1 || y == -1)
        return -1;
    if (x == 0)
    {
        leftMax = root->data;
        leftMin = root->data;
    }
    if (y == 0)
    {
        rightMin = root->data;
        rightMax = root->data;
    }

    if (root->data < leftMax || root->data > rightMin)
        return -1;

    min = leftMin;
    max = rightMax;

    if (x + y + 1 > size)
    {
        size = x + y + 1;
        bstRoot = root;
    }
    return x + y + 1;
}

TreeNode *findLargestBSTSubtree(TreeNode *root)
{
    TreeNode *bstRoot = NULL;
    int min, max;
    int maxNodes = INT_MIN;
    largestBST(root, min, max, maxNodes, bstRoot);
    return bstRoot;
}
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
        cout << vec[i] << ",";
    cout << vec[j];
}
int main()
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    TreeNode *subtree = findLargestBSTSubtree(root);

    printTree(subtree);

    return 0;
}
