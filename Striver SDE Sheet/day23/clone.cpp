
// Clone a Graph
// Given a graph and a node present in it create copy of graph and return same node in new graph

// We can Do BFS or DFS traversal and copy the graph

// in Cloning problems its better to use maps 

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// void DFS(Node *root, unordered_map<int, Node *> &m)
// {
//     Node *clone = new Node(root->val);
//     vector<Node *> temp;
//     m[root->val] = clone;
//     for (auto x : root->neighbors)
//     {
//         if (m.find(x->val) == m.end())
//             DFS(x, m);
//         temp.push_back(m[x->val]);
//     }
//     clone->neighbors = temp;
// }
// Node *cloneGraph(Node *root)
// {
//     if (root == NULL)
//         return NULL;
//     unordered_map<int, Node *> m;
//     DFS(root, m);
//     return m[1];
// }
// int main()
// {
    
//     return 0;
// }
