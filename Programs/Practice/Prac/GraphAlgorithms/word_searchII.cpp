#include <bits/stdc++.h>
using namespace std;

vector<string> res;
struct TrieNode
{
    struct TrieNode *child[26];
    bool isword;
    int id;
    TrieNode()
    {
        isword = false;
        id = -1;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
TrieNode *root;
void insert(string word, int x)
{
    struct TrieNode *temp = root;
    for (int i = 0; i < word.size(); i++)
    {
        int j = word[i] - 'a';
        if (temp->child[j] == NULL)
            temp->child[j] = new TrieNode();
        temp = temp->child[j];
    }
    temp->isword = true;
    temp->id = x;
}
void dfs(TrieNode *p, vector<vector<char>> &board,
         int i, int j, vector<string> &words)
{
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
    {
        if (p->isword && p->id != -1)
        {
            res.push_back(words[p->id]);
            p->id = -1;
        }
        return;
    }
    if (p->isword && p->id != -1)
    {
        res.push_back(words[p->id]);
        p->id = -1;
    }
    for (int k = 0; k < 26; k++)
    {
        if (p->child[k] != NULL && (k == (int)(board[i][j] - 'a')))
        {
            board[i][j] = '#';
            dfs(p->child[k], board, i + 1, j, words);
            dfs(p->child[k], board, i, j + 1, words);
            dfs(p->child[k], board, i - 1, j, words);
            dfs(p->child[k], board, i, j - 1, words);
            board[i][j] = (char)(k + 'a');
        }
    }
    return;
}
vector<string> findWords(vector<vector<char>> &board,
                         vector<string> &words)
{
    root = new TrieNode();
    for (int i = 0; i < words.size(); i++)
        insert(words[i], i);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            dfs(root, board, i, j, words);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                  {'e', 't', 'a', 'e'},
                                  {'i', 'h', 'k', 'r'},
                                  {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};

    vector<string> res = findWords(board, words);

    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ",";
    }
    cout << res[res.size() - 1] << "]";

    return 0;
}