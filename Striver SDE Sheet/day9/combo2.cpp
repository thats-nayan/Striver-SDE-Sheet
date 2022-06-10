
                    // Combination Sum2 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// My Efficient Method                  Time O(2^N *N)              Space O(2^N * K) 
// Uses a bit of extra space 
// void recursion(vector <pair<int,int>> &a,int i,int N,int sum,vector <int> temp,vector <vector<int>> &ans)
// {
//     if(sum == 0)
//     ans.push_back(temp);
//     else if(i == N)
//     return ;
//     else
//     {
//         int res = 0;
//         for (int j = 0; j <= a[i].second; j++)
//         {
//             if(res > sum)
//             break;
//             recursion(a,i+1,N,sum-res,temp,ans);
//             res += a[i].first;
//             temp.push_back(a[i].first);
//         }
//     }
// }
// vector <vector<int>> combo2(vector <int> &v,int sum)
// {
//     int N = v.size();
//     map <int,int> m;
//     for (int i = 0; i < N; i++)
//     m[v[i]]++;
//     vector <pair<int,int>> a;
//     for(auto x: m)
//     a.push_back(x);
//     vector <vector<int>> ans;
//     vector <int> temp;
//     recursion(a,0,a.size(),sum,temp,ans);
//     return ans;
// }
void recursion(vector <int> &v,int i,int N,int sum,vector <int> temp,vector <vector<int>> &ans)
{
    if(sum == 0)
    ans.push_back(temp);
    else if(sum < 0)
    return ;
    else
    {
        for (int j = i; j < N; j++)
        {
            if(j > i &&  v[j] == v[j-1] )   
            continue;
            if(v[j] > sum)
            continue;
            temp.push_back(v[j]);
            recursion(v,j+1,N,sum-v[j],temp,ans);
            temp.pop_back();
        }
    }
}
vector <vector<int>> combo2(vector <int> &v,int sum)
{
    int N = v.size();
    sort(v.begin(),v.end());
    vector <int> temp;
    vector <vector<int>> ans;
    recursion(v,0,N,sum,temp,ans);
    return ans;
}
int main()
{
    int N,sum;
    cin>>N>>sum;
    vector <int> v(N);
    for (int i = 0; i < N; i++)
    cin>>v[i];
    vector <vector<int>> ans = combo2(v,sum);
    for(auto x: ans)
    {
        for (int i = 0; i < x.size(); i++)
        cout<<x[i]<<" ";
        cout<<"\n";
    }
    return 0;
};