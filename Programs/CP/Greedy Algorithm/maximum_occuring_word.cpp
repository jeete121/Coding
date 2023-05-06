#include <bits/stdc++.h>
#define CHAR_SIZE 256
using namespace std;
struct Trie
{
  string key;
  int count=0;
  unordered_map<char,Trie*> character;
};
void insert(Trie *const &head,string &str)
{
  Trie *curr=head;
  for(int i=0;i<str.size();i++)
    {
        if(curr->character[str[i]]==nullptr)
           curr->character[str[i]]=new Trie();
        curr=curr->character[str[i]];
    }
   curr->key=str;
   curr->count+=1;
}
void preorder(Trie *const &curr,int &max_count,string  &str)
{
    if(curr==nullptr)
       return;
    for(auto pair:curr->character)
      {
          if(max_count<pair.second->count)
            {
                max_count=pair.second->count;
                str=pair.second->key;
            }
         preorder(pair.second,max_count,str);
      }
}
int main()
{
	string dict[] =
	{
		"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"
	};
   int n = sizeof(dict)/sizeof(dict[0]);
	Trie* head = new Trie();
	for (int i=0;i<n;i++)
		insert(head, dict[i]);
	int count = 0;
	string key;
	preorder(head, count, key);
	cout << "Word : " << key   << '\n';
	cout << "Count: " << count << '\n';

	return 0;
}