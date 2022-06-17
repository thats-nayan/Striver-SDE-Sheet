
                            // Trapping Rainwater 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Observation 
// Amount of water stored at block i is min(max(0..i,i..N)) - a[i]
// Brute Force 
// Run 2 nested loops to find maximum on left and maximum on right 

// Efficient Method 
// Make 2 arrays one for storing max element from left to right and another from right ot left 
int trap_rain(int a[],int N)
{
    int l[N],r[N];
    l[0] = a[0];
    r[N-1] = a[N-1];
    for (int i = 1; i < N; i++)
    l[i] = max(l[i-1],a[i]);
    for (int i = N - 2; i >= 0; i--)
    r[i] = max(r[i+1],a[i]);
    int ans = 0;
    for (int i = 1; i < N-1; i++)
    ans += min(l[i],r[i])-a[i];
    return ans;
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    cout<<trap_rain(a,N);
    return 0;
}