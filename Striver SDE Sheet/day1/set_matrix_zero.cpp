
// Brute Force 

// Store rows containing zero and columns containing zero in an unordered set and use that to check if element is to be set zero or not 
// Time O(m*n)                                                         Space O(m+n)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// void set_zero1(vector <vector<int>> &v)
// {
//     unordered_set <int> r,c;
//     int n = v.size();
//     int m = v[0].size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if(v[i][j] == 0)
//             {
//                 r.insert(i);
//                 c.insert(j);
//             }
//         }   
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if(r.find(i) != r.end() || c.find(j) != c.end())
//             v[i][j] = 0;
//         }   
//     }
// }
// Efficient Method 
// Instead of using auxiliary array or hash set we use first row and first column to decide 
// For first row we use a col variable to check 
// For first column we use value of first element to check 

void set_zero2(vector <vector<int>> &v)
{
    int r = v.size();
    int c = v[0].size();
    bool col = false;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(v[i][j] == 0)
            {
                if(i == 0)
                col = true;
                else if(j == 0)
                v[0][0] = 0;
                else 
                {
                    v[i][0] = 0;
                    v[0][j] = 0;
                }
            }
        }
    }
    for (int i = r- 1; i >= 0; i--)
    {
        for (int j = c-1; j >= 0; j--)
        {
            if(v[i][j] != 0)
            {
                if(i == 0)
                {
                    if(col)
                    v[i][j]  = 0;
                }
                else if(j == 0)
                {
                    if(v[0][0] == 0)
                    v[i][j] = 0;
                }
                else
                {
                    if(v[0][j] == 0|| v[i][0] == 0)
                    v[i][j] = 0;
                }
            }
        }
    }   
}
int main()
{
    int r,c;
    cin>>r>>c;
    vector <vector<int>> v(r,vector<int> (c,-1));
    for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
    cin>>v[i][j];
    // set_zero1(v);
    set_zero2(v);
    for (int i = 0; i < r; i++)
    {
       for (int j = 0; j < c; j++)
       cout<<v[i][j]<<" ";
       cout<<"\n"; 
    }
    return 0;
}