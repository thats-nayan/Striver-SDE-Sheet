                        // Minimum Spanning Tree 

// Spanning Tree is a graph which is a tree (n nodes with n-1 edges and every node is reachable from each other)
// Minimum spanning tree of a graph is a tree which has minimum sum of edges(weighted graph)

// To find minimum spanning tree in a graph we use 
// 1) Prims Algo 
// 2) Kruskals Algo 

// Using these we can find MST ,weight and everything 

// Prims Algo 

// Method 
// Start with 1st node and traverse all nodes in the adjency list and pick the edge and vertex with minimum weight
// Put that vertex in a ds 
// Next traverse all adjacent unvisited edges of vertex connected to vetex in the ds and pick minimum weight edge 
// Repeat this process untill u have all edges in the ds 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force to implement                 Gives TLE           Time O(N*N*N)
// int prims(vector <vector<int>> graph[],int V)
// {
//     unordered_set <int> s;
//     int ans = 0;
//     s.insert(0);
//     while(s.size() < V)
//     {
//         int MIN = INT32_MAX;
//         int ver;
//         for(auto x: s)
//         {
//             for(auto y: graph[x])
//             {
//                 if(s.find(y[0]) == s.end())
//                 {
//                     if(y[1] < MIN)
//                     {
//                         MIN = y[1];
//                         ver = y[0];
//                     }
//                 }
//             }
//         }
//         ans += MIN;
//         s.insert(ver);
//     }
//     return ans;
// }


// Better Method                 
// Maintain three arrays  key array mst array and parent array 
// Time O(N*N)                  Space O(V+E)
// int prims(int V,vector <vector<int>> adj[])
// {
//     int key[V],par[V];
//     // Key[i] stores minimum sum we need to spend to add vettex i
//     // par[i] stores parent of vertex i in minimum spanning tree    
//     // (Not required in sum problems but if we are asked to return minimum spanning tree then it is useful)
//     // mst[i] indicates whether vettex i is present in spanning tree or not at a particular instant
//     bool mst[V];
//     for (int i = 0; i < V; i++)
//     {
//         key[i] = INT32_MAX;
//         par[i] = -1;
//         mst[i] = false;
//     }
//     // Initialise all 3 arrays
//     int j = 0;
//     key[0] = 0;
//     int ans = 0;
//     while(j < V)
//     {
//         // Find vetex to be added in MST
//         int MIN = INT32_MAX;
//         int node;
//         for (int i = 0; i < V; i++)
//         {
//             if(mst[i] == false && key[i] < MIN)
//             {
//                 node = i;
//                 MIN = key[i];
//             }
//         }
//         ans += key[node];
//         mst[node] = true;
//         // Adding vetex to MST
//         for(auto x: adj[node])
//         {
//             if(mst[x[0]] == false && key[x[0]] > x[1])
//             {
//                 key[x[0]] = x[1];
//                 par[x[0]] = node;
//             }
//         }
//         // Traversing adjacency list of just added vertex to find next vertex to be added in MST 
//         j++;
//     }
//     return ans;
// }

// We can further optimise to O(V+E) using min priority queue for finding vetex with minimum weight 
// Time O(V+E) 
int prims(int V,vector <vector<int>> adj[])
{
    int key[V],par[V];
    // Key[i] stores minimum sum we need to spend to add vettex i
    // par[i] stores parent of vertex i in minimum spanning tree    
    // (Not required in sum problems but if we are asked to return minimum spanning tree then it is useful)
    // mst[i] indicates whether vettex i is present in spanning tree or not at a particular instant
    bool mst[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = INT32_MAX;
        par[i] = -1;
        mst[i] = false;
    }
    // Initialise all 3 arrays
    int j = 0;
    key[0] = 0;
    int ans = 0;
    priority_queue <pair<int,int>,vector <pair<int,int>>,greater <pair<int,int>>> pq;
    pq.push({0,0});
    while(pq.empty()==false)
    {
        // Find vetex to be added in MST
        int MIN = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(mst[node])
        continue;
        ans += key[node];
        mst[node] = true;
        // Adding vetex to MST
        for(auto x: adj[node])
        {
            if(mst[x[0]] == false && key[x[0]] > x[1])
            {
                pq.push({x[1],x[0]});
                key[x[0]] = x[1];
                par[x[0]] = node;
            }
        }
        // Traversing adjacency list of just added vertex to find next vertex to be added in MST 
        j++;
    }
    return ans;
}
int main()
{
    int V,E,x,y,W;
    cin>>V>>E;
    vector <vector<int>> graph[V];
    while(E--)
    {
        cin>>x>>y>>W;
        graph[x].push_back({y,W});
        graph[y].push_back({x,W});
    }
    cout<<prims(V,graph);
    return 0;
}