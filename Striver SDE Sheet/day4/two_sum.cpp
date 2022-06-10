
                            // Two Sum 

// Brute Force 
// Run nested loops                 Time O(N*N)            Space O(1)

// Efficient Method                 Time O(N)              Space O(N)
// Create hashmap and store elements in it 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector <int> two_sum(int a[],int N,int x)
{
    unordered_map <int,int> m;
    vector <int> ans;
    for (int i = 0; i < N; i++)
    {
        if(m.find(x-a[i]) != m.end())
        {
            ans.push_back(m[x-a[i]]);
            ans.push_back(i);
            break;
        }
        m[a[i]] = i;
    }
    return ans;
}
int main()
{
    int N,x;
    cin>>N>>x;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    vector <int> ans = two_sum(a,N,x);
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}