
//  Detect Cycle in Directed Graph 

// DFS Approach 
// There exists a cycle if there is back edge in graph 
// Back edge is edge which connects 2 vertex which are present in same recursion stack 
// Time O(V+E)                                 Space O(V+E) 

// BFS Approach (Use Topo Sort )
// If topo sort of a graph is not possible then it is directed cycle graph 
// e nodes present in cycle will have non zero indegree after BFS and would not be present in topo sort  
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(int x,int y,vector <int> adj[])
{
    adj[x].push_back(y);
    // adj[y].push_back(x);
}
bool DFS(vector <int> adj[],int i,bool visited[],bool res[])
{
    for(auto x: adj[i])
    {
        if(res[x])
        return true;
        else
        {
            visited[x] = true;
            res[x] = true;
            if(DFS(adj,x,visited,res))
            return true;
        }
    }
    res[i] = false;
    return false;
}
bool detect_cycle(vector <int> adj[],int V)
{
    bool visited[V],res[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        res[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        {

            visited[i] = true;
            res[i] = true;
            if(DFS(adj,i,visited,res))
            return true;
        }
    }
    return false;
}
bool BFS(vector <int> adj[],int V)
{
    int indegree[V] = {0};
    for(int i = 0 ; i < V ; i++)
    {
        for(auto x: adj[i])
        indegree[x]++;
    }
    queue <int> q;
    for(int i = 0 ; i < V ; i++)
    if(indegree[i] == 0)
    q.push(i);
    int count = 0;
    while(q.empty() == false)
    {
        int p = q.front();
        q.pop();
        count++;
        for(auto x: adj[p])
        {
            indegree[x]--;
            if(indegree[x] == 0)
            q.push(x);
        }
    }
    return count < V;
}
int main()
{
    int x,y,V,E;
    cin>>V>>E;
    vector <int> adj[V];
    while(E--)
    {
        cin>>x>>y;
        addEdge(x,y,adj);
    }
    cout<<detect_cycle(adj,V);
    return 0;
}