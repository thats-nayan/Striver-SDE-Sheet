
                            // Longest Complete String 

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
    public :
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
    bool check_prefix(string &word)
    {
        TrieNode *node = root;
        int N = word.length();
        for (int i = 0; i < N; i++)
        {
            if(node->child[word[i]-'a'] == NULL)
            return false;
            node = node->child[word[i]-'a'];
            if(node->isEnd == false)
            return false;
        }
        return true;
    }
};
string all_prefix(vector <string> &word)
{
    Trie T;
    for(auto x: word)
    T.insert(x);
    string ans = "";
    for(auto x: word)
    {
        if(T.check_prefix(x))
        {
            if(x.length() > ans.length())
            ans = x;
            else if(x.length() == ans.length() && ans.compare(x) > 0)
            ans = x;
        }
    }
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector <string> word(N);
    for (int i = 0; i < N; i++)
    cin>>word[i];
    cout<<all_prefix(word);
    return 0;
}