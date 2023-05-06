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

string serialize(TreeNode *root)
{
    if (!root)
    {
        return "X#";
    }
    string l = serialize(root->left);
    string r = serialize(root->right);

    return to_string(root->data) + "#" + l + r;
}

// pre-order traversal
TreeNode *dfs(vector<string> &nodes, int &loc)
{
    if (loc >= nodes.size())
    {
        return nullptr;
    }

    string val = nodes[loc];
    if (val.size() == 1 && val[0] == 'X')
    {
        return nullptr;
    }

    TreeNode *node = new TreeNode(stoi(val));
    node->left = dfs(nodes, ++loc);
    node->right = dfs(nodes, ++loc);

    return node;
}

vector<string> split(string &str, char delim)
{
    vector<string> result;
    int i = 0;

    while (i < str.length())
    {
        int pos = str.find(delim, i);

        if (pos == string::npos)
        {
            string tmp = str.substr(i, str.size() - 1);
            result.push_back(tmp);
            break;
        }

        string tmp = str.substr(i, pos - i);
        result.push_back(tmp);
        i = pos + 1;
    }

    return result;
}

TreeNode *deserialize(string data)
{
    vector<string> nodes = split(data, '#');

    int loc = 0;
    TreeNode *root = dfs(nodes, loc);

    return root;
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string str = serialize(root);
    cout << "Serialize string is " << str << "\n";

    printTree(root);
    return 0;
}