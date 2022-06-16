
// Kosaraju Algorithm 
// Used to find all strongly connected components in a directed graph 

// Strongly Connected Component : If u start at any node u can every other node in component 

// Intuition 
// If we do DFS from nodes which cant visit more vertices we cna get strongly connected componenets 
// Kosaraju algo is based on this 

// Method 
// Step 1 
// Sort all nodes in order of finisihing time    (Topological Sort) Use DFS to find 

// Step 2
// Transpose the graph (Reverse all edges of graph)

// Step 3 
// Do DFS traversal in order of vertex obtained in Step 1 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void DFS(vector <int> adj[],bool visited[],int i,stack <int> &st,int step)
{
    for(auto x: adj[i])
    {
        if(visited[x] == false)
        {
            visited[x] = true;
            DFS(adj,visited,x,st,step);
        }
    }
    if(step == 1)
    st.push(i);
}
void kosaraju(vector <int> adj[],int V)
{
    stack <int> st;
    bool visited[V];
    for (int i = 0; i < V; i++)
    visited[i] = false;
    // Step 1 
    for (int i = 0; i < V; i++)
    {
        for(auto x: adj[i])
        {
            if(visited[x] == false)
            {
                visited[x] = true;
                DFS(adj,visited,i,st,1);
            }
        }
    }
    // Step 2
    vector <int> trans[V];
    for (int i = 0; i < V; i++)
    {
        for(auto x: adj[i])
        trans[x].push_back(i);
        visited[i] = false;
    }
    // Step 3
    int ans = 0;
    while(st.empty()==false)
    {
        if(visited[st.top()] == false)
        {
            visited[st.top()] = true;
            DFS(trans,visited,st.top(),st,3);
            cout<<"\n";
            ans++;
        }
        st.pop();
    }
}
int main()
{
    int V,E,x,y;
    cin>>V>>E;
    vector <int> adj[V];
    for (int i = 0; i < E; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    kosaraju(adj,V);
    return 0;
}