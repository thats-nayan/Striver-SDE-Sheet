                    // N Queen Problem 

// Place N Queens on a N*N chessboard so that none of them attack each other 
// Try to place one queen in every column and check whether it wont affect other queens 
// Time O(n*n!)                     Space O(n^2) 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool is_feasible(vector <string> &board,int i,int j,int N)
{
    for (int k = j-1; k >= 0; k--)
    if(board[i][k] == 'Q')
    return false;
    int k = i-1;
    int l = j-1;
    while(k >= 0 && l >= 0)
    {
        if(board[k][l] == 'Q')      
        return false;
        k--;
        l--;
    }
    k = i+1;
    l = j-1;
    while(k < N && l >= 0)
    {
        if(board[k][l] == 'Q')      
        return false;
        k++;
        l--;
    }      
    return true;
}
void backtrack(int j,int N,vector <string> &board,vector <vector<string>> &ans)
{
    if(j == N)
    ans.push_back(board);
    else
    {
        for (int i = 0; i < N; i++)
        {
            if(is_feasible(board,i,j,N))
            {
                board[i][j] = 'Q';
                backtrack(j+1,N,board,ans);
                board[i][j] = '.';
            }
        }
    }
}
vector <vector<string>> nqueen(int N)
{   
    vector <vector<string>> ans;
    string temp = "";
    for (int i = 0; i < N; i++)
    temp.push_back('.');
    vector <string> board;
    for (int i = 0; i < N; i++)
    board.push_back(temp);
    backtrack(0,N,board,ans);
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector <vector<string>> ans = nqueen(N);
    for(auto x: ans)
    {
        for (int i = 0; i < x.size(); i++)
        cout<<x[i]<<"\n";
        cout<<"\n";
    }
    return 0;
}