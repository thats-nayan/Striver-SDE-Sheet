
// Sudoku Solver
// Time O(9^n*n)                       Space O(1) 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool is_feasible(vector<vector<char>> &v, int i, int j, char c)
{
    for (int k = 0; k < 9; k++)
        if (v[i][k] == c)
            return false;
    for (int k = 0; k < 9; k++)
        if (v[k][j] == c)
            return false;
    for (int k = (i / 3) * 3; k < ((i / 3) * 3) + 3; k++)
    {
        for (int l = (j / 3) * 3; l < ((j / 3) * 3) + 3; l++)
            if (v[k][l] == c)
                return false;
    }
    return true;
}
bool back_track(vector<vector<char>> &v, int i, int j)
{
    if (i == 9 && j == 0)
        return true;
    else if (v[i][j] != '.')
    {
        if (j == 8)
        return back_track(v, i + 1, 0);
        else
        return back_track(v, i, j + 1);
    }
    for (char c = '1'; c <= '9'; c++)
    {
        if (is_feasible(v, i, j, c))
        {
            v[i][j] = c;
            if (j == 8)
            {
                if(back_track(v,i+1,0) == false)
                v[i][j] = '.';
            }
            else
            {
                if(back_track(v,i,j+1) == false)
                v[i][j] = '.';
            }
        }
    }
    if(v[i][j] == '.')
    return false;
    else
    return true;
}
void sudoku(vector<vector<char>> &v)
{
    back_track(v, 0, 0);
}
int main()
{
    vector<vector<char>> v(9, vector<char>(9, -1));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> v[i][j];
    sudoku(v);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    return 0;
}