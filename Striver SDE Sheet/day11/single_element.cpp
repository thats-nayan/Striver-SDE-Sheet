
// Find element which apears once in array where everr element appears twice 

// Brute Force 
// Do xor of each element                       Time O(N)               Space o(1)
// Efficient Approach 
// Structure of array 
// For even indeices 
// a[even] == a[even+1]  Then at one even index a[even] != a[even-1]
// answer = a[k] where k is last even index where a[k] != a[k-1]
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int single(int a[],int N)
{
    int l = 0,r = N-1;
    if(N == 1)
    return a[0];
    if(N == 3)
    {
        if(a[2] == a[1])
        return a[0];
        else
        return a[2];
    }
    if(a[N-1] != a[N-2])
    return a[N-1];
    if(a[0] != a[1])
    return a[0];
    while(l < r)
    {
        int m = (l+r)/2;
        if(m&1)
        m--;
        if(m == l)
        return a[l];
        if(a[m] == a[m-1])
        r = m;
        else
        l = m;
    }
    return a[l];
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    cout<<single(a,N)<<"\n";
    return 0;
}