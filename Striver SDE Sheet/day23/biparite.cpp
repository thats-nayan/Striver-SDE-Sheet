
// Bipartite Graph
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
// OR
// We can color graph with 2 colors such that no 2 connected vertex have the same color
// Observation
// A graph having atleast one odd length cycle is not a bipartite graph

// Method 
// Do Normal BFS or DFS Traversal and check for cycles of odd length 
// Time O(V+E)                      Space O(V+E)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool BFS(vector <vector<int>> &graph,int i,int visited[])
{
    queue <int> q;
    q.push(i);
    visited[i] = 1;
    while(q.empty() == false)
    {
        int p = q.front();
        int y = visited[p];
        q.pop();
        for(auto x: graph[p])
        {
            if(visited[x] != -1 && (y+1-visited[x])%2 != 0)
            return true;
            else if(visited[x] == -1)
            {
                q.push(x);
                visited[x] = y+1;
            }
        }
    }
    return false;
}
bool DFS(vector <vector<int>> &graph,int i,int visited[])
{
    int y = visited[i];
    for(auto x: graph[i])
    {
        if(visited[x] != -1 && (y+1-visited[x])%2 != 0)
        return true;
        else if(visited[x] == -1)
        {
            visited[x] = y+1;
            if(DFS(graph,x,visited))
            return true;
        }
    }
    return false;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    int visited[V];
    for (int i = 0; i < V; i++)
    visited[i] = -1;
    for (int i = 0; i < V; i++)
    {
        if(visited[i] == -1)
        {
            visited[i] = 1;
            if(DFS(graph,i,visited))
            return false;
        }
    }   
    return true;
}
int main()
{
    int x, y, V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    while (E--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout <<isBipartite(adj);
    return 0;
}