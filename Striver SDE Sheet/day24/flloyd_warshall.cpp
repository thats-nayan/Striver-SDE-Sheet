
                            // All Pair Shortest path Algorithm 

// Used to find minimum distnace between all pairs of vertices in weighted graph 

// First find shortest path between i and j vetex without including any vertex , then include 1st vetex and check if we find any other shorter path  Repeat this process untill we add all vertex in shortest path

// dis[i][j] = dis[i][k]+dis[k][j]  we use this formula to find shortest distance

// This algo works on both directed as well as undirected graph 
// This algo also works for negative weight edges 
// But if there are negative weight cycle then it does not work becuase shortest distnace does not exist 

// Time O(N*N*N)  Space O(1) 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void flloyd(vector <vector<int>> &dis)
{
    int N = dis.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        if(dis[i][j] == -1)
        dis[i][j] = 1e8;
    }
    for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        if(dis[i][j] > 1e6)
        dis[i][j] = -1;
    }
    
}
int main()
{
    int N;
    cin>>N;
    vector <vector<int>> dis(N,vector <int> (N));
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    cin>>dis[i][j];
    flloyd(dis);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        cout<<dis[i][j]<<" ";
        cout<<"\n";
    }
    
    return 0;
}