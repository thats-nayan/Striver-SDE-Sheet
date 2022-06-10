
// Variations of This Problem 
// 1) Find element at at a given position       (r-1) C (c-1)    Time O(n)   Space O(1)
// 2) Print given row of Pascal Triangle                Time O(n)      Space O(1)
// 3) Print whole Pascal triangle 

// Pascal Triangle 

    ///    1
    //    1 1 
    //   1 2 1 
    //  1 3  3 1
    // 1  4 6 4  1 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector <vector<int>> pascal(int N)
{
    vector <vector<int>> v;
    for (int i = 0; i <= N; i++)
    {
        vector <int> temp;
        for (int j = 0; j <= i; j++)
        {
            if(j == 0 || j == i)
            temp.push_back(1);
            else
            temp.push_back(v[i-1][j]+v[i-1][j-1]);
        }
        v.push_back(temp);
    }
    return v;
}
int main()
{
    int N;
    cin>>N;
    vector <vector<int>> ans = pascal(N);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
