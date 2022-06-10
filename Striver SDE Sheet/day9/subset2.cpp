
                    // Generate Unique Subsets

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force 
// Generate all unique subsets and put them in hashset and return it
// Time O(2^N * log(2^N))                 Space O(2^N) 

// My Efficient Method  Used a bit of extra space
// void recursion(vector <pair<int,int>> &a,vector <int> temp,int i,int N,vector <vector<int>> &ans)
// {
//     if(i == N)
//     ans.push_back(temp);
//     else
//     {
//         for (int j = 0; j <= a[i].second; j++)
//         {
//             recursion(a,temp,i+1,N,ans);
//             temp.push_back(a[i].first);   
//         }
//     }
// }
// vector <vector<int>> subsets2(vector <int> &v)
// {
//     int N = v.size();
//     unordered_map <int,int> m;
//     for(int i = 0 ;i < N ; i++)
//     m[v[i]]++;
//     vector <pair<int,int>> a;
//     for(auto x: m)
//     a.push_back(x);
//     int z = a.size();
//     vector <vector<int>> ans;
//     vector <int> temp;
//     recursion(a,temp,0,z,ans);
//     return ans;
// }
// Striver Efficient Method 
void recursion(vector <int> &a,int i,int N,vector <int> temp,vector <vector<int>> &ans)
{
    for (int j = i; j < N; j++)
    {
        if(j > i && a[j] == a[j-1])   
        continue;
        temp.push_back(a[j]);
        recursion(a,j+1,N,temp,ans);
        ans.push_back(temp);
        temp.pop_back();
    }
}
vector <vector<int>> subset2(vector <int> &v)
{
    int N = v.size();
    sort(v.begin(),v.end());
    vector <vector<int>> ans;
    vector <int> temp;
    ans.push_back(temp);
    recursion(v,0,N,temp,ans);
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector <int> a(N);
    for (int i = 0; i < N; i++)
    cin>>a[i];
    vector <vector<int>> ans = subset2(a);
    for(auto x: ans)
    {
        for (int i = 0; i < x.size(); i++)
        cout<<x[i]<<" ";
        cout<<"\n";
    }
    return 0;
}