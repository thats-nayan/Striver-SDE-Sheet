
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Observations 
// Check if binary tree is complete 
// Check if it satisfies heap property 
// If both satisfy then yes else no 
struct Node
{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
// Time O(n)                        Space O(n)
bool isHeap(Node *root)
{
    queue <Node *> q;
    q.push(root);
    bool found = true;
    while(q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        int MAX = curr->data;
        if(curr->left != NULL)
        {
            if(found)
            {
                q.push(curr->left);
                MAX = max(MAX,curr->left->data);
            }
            else
            return false;
        }
        else
        found = false;
        if(curr->right != NULL)
        {
            if(found)
            {
                q.push(curr->right);
                MAX = max(MAX,curr->right->data);
            }
            else
            return false;
        }
        else
        found = false;
        if(curr->data != MAX)
        return false;
    }
    return true;
}
int main()
{
    
    return 0;
}