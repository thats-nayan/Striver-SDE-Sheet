
// Brute Force 
// Make another matrix and copy first row in last column , second row in second last column and so on  
// Time O(N*N)                      Space O(n*N)

// Efficient Approach 
// Take transpose of matrix  and swap columns firs with last , second with second last and so on 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void rotate90(vector <vector <int>> &v)
{
    int N = v.size();
    for (int i = 0; i < N; i++)
    for (int j = 0; j < i; j++)
    swap(v[i][j],v[j][i]);
    for (int j = 0; j < N/2; j++)
    for (int i = 0; i < N; i++)
    swap(v[i][j],v[i][N-1-j]);  
}
int main()
{   
    int N;
    cin>>N;
    vector <vector<int>> v(N,vector <int> (N,-1));
    for (int i = 0; i < N; i++)
    for (int h = 0; h < N; h++)
    cin>>v[i][h];
    rotate90(v);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        cout<<v[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}