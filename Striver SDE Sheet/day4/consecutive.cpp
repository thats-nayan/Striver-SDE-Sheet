
        // Find Length of Longest Consecutive Sequence 

// Brute Force 
// Sort the array and check difference between ajacenet elements to count 
// Time O(NlogN)                       Space O(1)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int consecutive(vector <int> &v)
// {
//     int N = v.size();
//     if(N == 0)
//     return N;
//     sort(v.begin(),v.end());
//     int ans = 0;
//     int sum = 1;
//     for (int i = 1; i < N; i++)
//     {
//         if(v[i]-v[i-1] > 2)
//         {
//             ans = max(ans,sum);
//             sum = 1;
//         }
//         else if(v[i]-v[i-1] == 1)
//         sum++;
//     }
//     ans = max(ans,sum);
//     return ans;
// }
// Efficient Method 
// Use HashSet to store all values and traverse each sequence from its starting element 
// Tine O(N)                       Space O(N) 
int consecutive(vector <int> &v)
{
    int N = v.size();
    if(N == 0)
    return 0;
    unordered_set <int> s;
    for (int i = 0; i < N; i++)
    s.insert(v[i]);
    int ans = 0;
    for(auto x: s)
    {
        if(s.find(x-1) == s.end())
        {
            int curr = 0;
            while(s.find(x+curr) != s.end())
            curr++;
            ans = max(ans,curr);
        }
    }
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector <int> v(N);
    for (int i = 0; i < N; i++)
    cin>>v[i];
    cout<<consecutive(v);
    return 0;
}