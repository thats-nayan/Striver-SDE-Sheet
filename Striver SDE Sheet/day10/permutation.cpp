
                    // Print All Permutations of A string/ Array 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Method 1                     Iterative Method
// Sort the array and use next permutation n! times 
// Time O(N! * N)                                       Space O(1)
void next_permutation(vector <int> &v)
{
    int N = v.size();
    bool found = false;
    for (int i = N-1; i >= 1; i--)
    {
        if(v[i-1] < v[i])
        {
            found = true;
            for (int j = N- 1; j >= 0; j--)
            {
                if(v[j] > v[i-1])
                {
                    // cout<<"v(i-1) = "<<v[i-1]<<" v(j) = "<<v[j]<<"\n";
                    swap(v[i-1],v[j]);
                    break;
                }
            }
            reverse(v.begin()+i,v.end());
            break;
        }
    }
    if(found == false)
    reverse(v.begin(),v.end());
}
// vector <vector<int>> permutation(vector <int> &a)
// {
//     int N = a.size();
//     sort(a.begin(),a.end());
//     int fac = 1;
//     for (int i = 2; i <= N; i++)
//     fac *= i;
//     fac--;
//     vector <vector<int>> ans;
//     ans.push_back(a);
//     while(fac--)    
//     {
//         next_permutation(a);
//         ans.push_back(a);
//     }
//     return ans;
// }
// Method 2                 Using Recursion 
// Time O(N!*N)                                Space O(1) 
void recursion(vector <int> a,int i,int N,vector <vector<int>> &ans)
{
    if(i == N)
    ans.push_back(a);
    else
    {
        for (int j = i; j < N; j++)
        {
            swap(a[i],a[j]);
            recursion(a,i+1,N,ans);
            swap(a[i],a[j]);
        }
    }
}
vector <vector<int>> permutation(vector <int> &a)
{
    vector <vector<int>> ans;
    int N = a.size();
    recursion(a,0,N,ans);
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector <int> a(N);
    for (int i = 0; i < N; i++)
    cin>>a[i];
    vector <vector<int>> ans = permutation(a);
    for(auto x: ans)
    {
        for (int i = 0; i < x.size(); i++)
        cout<<x[i]<<" ";
        cout<<"\n";
    }
    return 0;
}