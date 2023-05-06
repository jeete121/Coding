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

//function to encode tree into
//the string
string serialize(TreeNode *root)
{
    if (root == NULL)
        return "";
    string ans = to_string(root->data) + ",";

    //call for left subtree
    ans += serialize(root->left);

    //call for right subtree
    ans += serialize(root->right);
    return ans;
}

//function to find the nth
int findnth(string &data, int &pos)
{
    pos = data.find(",");
    int val1 = stoi(data.substr(0, pos));
    return val1;
}
TreeNode *deserialize(string &data, int max1)
{
    int pos = 0;
    if (data.size() == 0)
        return NULL;
    int val1 = findnth(data, pos);
    if (val1 > max1)
        return NULL;

    //store the substring from pos+1 to end
    data = data.substr(pos + 1);

    //make the root
    TreeNode *root = new TreeNode(val1);

    //call for left subtree
    root->left = deserialize(data, val1);

    //call for right subtree
    root->right = deserialize(data, max1);
    return root;
}
// function to decodes the encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    return deserialize(data, INT_MAX);
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
    cout << vec[j];
    cout << "]";
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    string data = serialize(root);
    root = deserialize(data);
    printTree(root);
    return 0;
}