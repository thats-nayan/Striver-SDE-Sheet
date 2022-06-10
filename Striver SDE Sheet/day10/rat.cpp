
// Rat in a Maze 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void backtrack(vector <vector<int>> &v,vector <vector<bool>> &visited,int i,int j,int n,string temp,vector <string> &ans)
{
    if(i == n-1 && j == n-1)
    ans.push_back(temp);
    else
    {
        visited[i][j] = true;
        if(i+1 < n && v[i+1][j] == 1 && visited[i+1][j] == false)
        {
            temp.push_back('D');
            backtrack(v,visited,i+1,j,n,temp,ans);
            temp.pop_back();
        }
        if(j-1 >= 0 && v[i][j-1] == 1 && visited[i][j-1] == false)
        {
            temp.push_back('L');
            backtrack(v,visited,i,j-1,n,temp,ans);
            temp.pop_back();
        }
        if(j+1 < n && v[i][j+1] == 1 && visited[i][j+1] == false)
        {
            temp.push_back('R');
            backtrack(v,visited,i,j+1,n,temp,ans);
            temp.pop_back();
        }
        if(i-1 >= 0 && v[i-1][j] == 1 && visited[i-1][j] == false)
        {
            temp.push_back('U');
            backtrack(v,visited,i-1,j,n,temp,ans);
            temp.pop_back();
        }
        visited[i][j] = false;
    }
}
vector <string> rat(vector <vector<int>> &v,int n)
{
    vector <string> ans;
    if(v[0][0] == 0 || v[n-1][n-1] == 0)
    return ans;
    vector <vector<bool>> visited(n,vector <bool> (n,false));
    string temp = "";
    backtrack(v,visited,0,0,n,temp,ans);
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector <vector<int>> v(N,vector <int> (N,-1));
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    cin>>v[i][j];
    vector <string> ans = rat(v,N);
    for(auto x: ans)
    cout<<x<<"\n";
    return 0;
}