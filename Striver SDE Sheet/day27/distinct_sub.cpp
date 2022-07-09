
                    // Distinct Substrings 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force 
// Insert all substrings in a set 
// Time O(N*N log M)                        Space O(N*N)
// Efficient Method 
// Use Trie
// Time O(N*N)                Space O(26*)
class TrieNode{
    public:
    TrieNode *child[26];
    bool isEnd ;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        child[i] = NULL;
        isEnd = false;
    }
};
class Trie
{
    public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    int count_sub(string &s)
    {
        TrieNode *node = root;
        int ans = 1;
        int N = s.length();
        for (int i = 0; i < N; i++)
        {
            node = root;
            for (int j = i; j < N; j++)
            {
                if(node->child[s[j]-'a'] == NULL)
                {
                    ans++;
                    node->child[s[j]-'a'] = new TrieNode();
                }
                node = node->child[s[j]-'a'];
            }
        }
        return ans;
    }
};
int distinct_substrings(string &s)
{
    Trie T;
    return T.count_sub(s);
}
int main()
{
    string s;
    cin>>s;
    cout<<distinct_substrings(s);
    return 0;
}