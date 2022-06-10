
// Method 1 
// Use inbuilt next permutation 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Method 
// 1) Traverse from back and find first index fro which v[i-1] < v[i] 
// 2) Traverse from back and find just graeter index than v[i-1] 
// swap v[j] && v[i-1] 
// Reverse array from i to end 
vector <int> next_permutation(vector <int> &v)
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
    return v;
}
int main()
{
    int N;
    cin>>N;
    vector <int> v(N);
    for (int i = 0; i < N; i++)
    cin>>v[i];
    vector <int> ans = next_permutation(v);
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}