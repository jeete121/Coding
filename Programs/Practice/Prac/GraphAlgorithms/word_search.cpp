#include <bits/stdc++.h>
using namespace std;

//structure for trie
struct Trie
{
     bool isleaf;
     unordered_map<char,Trie*> ump;
     Trie()
        {
          isleaf=false;
        }
};

//create a new node
Trie *newNode()
{
    Trie *node=new Trie();
    return node;
}

//function to insert the word into the trie
void insert(Trie *head,string word)
{
    //if head is null then 
    //create a new node
     if(head==NULL)
         head=newNode();
      Trie *curr=head;

       //iterate till the length of word
      for(int i=0;i<word.size();i++)
        {

            //if current element of word is not
            //present the create a new node for it
            if(curr->ump.find(word[i])==curr->ump.end())
                   curr->ump[word[i]]=newNode();

            //update the current  to the new character
            //of the string
            curr=curr->ump[word[i]];
        }

       //mark the isleaf as true 
       
        curr->isleaf=true;
}

bool dfs(Trie *curr,vector<vector<char>> &board,int i,int j)
{
      //base case if current leaf is true
      //then return true as the word is found in the grid
      if(curr->isleaf)
               return true;

      //check for valid cell or not
      if(i<0||j<0||i>=board.size()||j>=board[0].size()||(curr->ump.find(board[i][j])==curr->ump.end()))
                return false;

       //store the current cell data
      char ch=board[i][j];
      
      //mark is as visited
      board[i][j]='.';

      //call dfs for all four directions
      if(dfs(curr->ump[ch],board,i-1,j)||dfs(curr->ump[ch],board,i+1,j)||dfs(curr->ump[ch],board,i,j-1)||dfs(curr->ump[ch],board,i,j+1))
         return true;

      //reset the current data as the previous 
      //as same as backtrack
      board[i][j]=ch;

      //if word is not found then return false
     return false;
}


//function to check if word is found in the grid or
//not
bool exist(vector<vector<char>>& board, string word) 
{

    //create a new trie
    Trie *node=new Trie();

    //insert the word into the trie
    insert(node,word);
    Trie *temp=node;

    //iterate for all cells
     for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board[0].size();j++)
                if(temp->ump[board[i][j]]&&dfs(node,board,i,j))
                         return true;
       }
        return false;
}

int main()
{
    vector<vector<char>>board ={{'A','B','C','E'},
                               {'S','F','C','S'},
                               {'A','D','E','E'}};
    string word="ABCCED";
    if(exist(board,word))
      cout<<"true";
    else
     cout<<"false";
    
   return 0;
}