
                        // Best Time to Buy and Sell Stock 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int stock1(vector <int> &v)
{
    int N = v.size();
    int MIN = v[0];
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        MIN = min(MIN,v[i]);
        ans = max(ans,v[i]-MIN);
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
    cout<<stock1(v);
    return 0;
}