// Trie Representation

// Insert Word , Search Word and Search Prefix Functions 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        child[i] = NULL;
        isEnd = false;
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
        }
        node->isEnd = true;
    }
    bool search(string word)
    {
        TrieNode *node = root;
        int N = word.length();
        for (int i = 0; i < N; i++)
        {
            if(node->child[word[i]-'a'] == NULL)
            return false;
            node = node->child[word[i]-'a'];
        }
        return (node->isEnd);
    }
    bool startswith(string word)
    {
        TrieNode *node = root;
        int N = word.length();
        for (int i = 0; i < N; i++)
        {
            if(node->child[word[i]-'a'] == NULL)
            return false;
            node = node->child[word[i]-'a'];
        }
        return true;
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
        else
        {
            cin>>word;
            cout<<T.startswith(word)<<"\n";
        }
    }
}