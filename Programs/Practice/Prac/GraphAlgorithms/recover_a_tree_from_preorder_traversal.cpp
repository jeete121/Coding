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

int pos;
TreeNode *recoverTree(string &traversal, int level)
{
    //if we reach end of the string
    //then return NULL
    if (traversal[pos] == '\0')
        return NULL;
    int curr = 0;

    //count depth of the next node
    while (traversal[pos + curr] == '-')
        curr++;

    //if depth of node is same as level
    if (curr == level)
    {
        pos += curr;
        int val = 0;

        //get the value at the current node
        while (traversal[pos] >= '0' && traversal[pos] <= '9')
        {
            val = (val * 10) + traversal[pos] - '0';
            pos++;
        }

        //create a new node with that value
        TreeNode *root = new TreeNode(val);

        //call for left by increasing a level
        root->left = recoverTree(traversal, level + 1);

        //call for right by increasing a level
        root->right = recoverTree(traversal, level + 1);

        //return the root of the tree
        return root;
    }

    //return null
    return NULL;
}
TreeNode *recoverFromPreorder(string traversal)
{

    pos = 0;
    return recoverTree(traversal, 0);
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
    cout << "[";
    for (int i = 0; i < j; i++)
        cout << vec[i] << ",";
    cout << vec[j];
    cout << "]";
}
int main()
{
    string traversal = "1-2--3--4-5--6--7";

    TreeNode *root = recoverFromPreorder(traversal);

    printTree(root);

    return 0;
}