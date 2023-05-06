#include <bits/stdc++.h>
using namespace std;

//structure for the trie
struct Trie
{
    bool isleaf;
    unordered_map<char, Trie *> ump;
    Trie()
    {
        isleaf = false;
    }
};

//function to create a new node
Trie *newNode()
{
    Trie *node = new Trie();
    return node;
}

//function to insert the word into the trie
void insert(Trie *head, string word)
{

    //if head is null then create
    //a new node for head
    if (head == NULL)
        head = newNode();

    //point to the head
    Trie *curr = head;

    //iterate for all the characters of the word
    for (int i = 0; i < word.size(); i++)
    {

        //if not fount then create a new node
        if (curr->ump.find(word[i]) == curr->ump.end())
            curr->ump[word[i]] = newNode();

        //move to next node
        curr = curr->ump[word[i]];
    }

    //mark leaf as true
    curr->isleaf = true;
}

//dfs function to search the word in the noard
bool dfs(Trie *curr, vector<vector<char>> &board, int i, int j)
{

    //if word is found then return true
    if (curr->isleaf)
        return true;

    //if current cell is invalid then return false
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || (curr->ump.find(board[i][j]) == curr->ump.end()))
        return false;

    //store the current character of the cell
    char ch = board[i][j];
    board[i][j] = '.';

    //check for all four directions
    if (dfs(curr->ump[ch], board, i - 1, j) ||
        dfs(curr->ump[ch], board, i + 1, j) ||
        dfs(curr->ump[ch], board, i, j - 1) ||
        dfs(curr->ump[ch], board, i, j + 1))
        return true;

    //backtrack
    board[i][j] = ch;
    return false;
}
bool exist(vector<vector<char>> &board, string word)
{
    Trie *node = new Trie();
    insert(node, word);
    Trie *temp = node;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
            if (temp->ump[board[i][j]] && dfs(node, board, i, j))
                return true;
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    if (exist(board, word))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}