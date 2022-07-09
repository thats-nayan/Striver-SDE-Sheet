
// Trie Representation

// Insert Word , Count Word Having Given Prefix , Count Frequency of Word , Delete Word Operation

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    TrieNode *child[26];
    int CountEnd;
    int CountPre;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        child[i] = NULL;
        CountEnd = 0;
        CountPre = 0;
    }
};
class Trie{
    public:
    TrieNode *root;
    Trie()
    {
		root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *node = root;
        int N = word.length();
        for (int i = 0; i < N; i++)
        {
            if(node->child[word[i]-'a'] == NULL)
            node->child[word[i]-'a'] = new TrieNode();
            node = node->child[word[i]-'a'];
            node->CountPre++;
        }
        node->CountEnd++;
    }
    int search(string word)
    {
        TrieNode *node = root;
        int N = word.length();
        for (int i = 0; i < N; i++)
        {
            if(node->child[word[i]-'a'] == NULL)
            return false;
            node = node->child[word[i]-'a'];
        }
        return (node->CountEnd);
    }
    int startswith(string word)
    {
        TrieNode *node = root;
        int N = word.length();
        for (int i = 0; i < N; i++)
        {
            if(node->child[word[i]-'a'] == NULL)
            return 0;
            node = node->child[word[i]-'a'];
        }
        return node->CountPre;
    }
    void delete_word(string word)
    {
        TrieNode *node = root;
        int N = word.length();
        for (int i = 0; i < N; i++)
        {
            if(node->child[word[i]-'a'] == NULL)
            node->child[word[i]-'a'] = new TrieNode();
            node = node->child[word[i]-'a'];
            node->CountPre--;
        }
        node->CountEnd--;
    }
};
int main()
{   
    Trie T;
    string word;
    int Q,t;
    cin>>Q;
    while(Q--)
    {
        cin>>t;
        if(t == 1)
        {
            cin>>word;
            T.insert(word);
        }
        else if(t == 2)
        {
            cin>>word;
            cout<<T.search(word)<<"\n";
        }
        else if(t == 3)
        {
            cin>>word;
            cout<<T.startswith(word)<<"\n";
        }
        else
        {
            cin>>word;
            T.delete_word(word);
        }
    }
}