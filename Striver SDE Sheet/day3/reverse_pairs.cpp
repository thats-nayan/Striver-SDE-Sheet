
                    // Reverse Pairs 
                
// find pairs i and j such that a[i] > 2*a[j] and i < j 

// Brute Force 
// Run 2 nested loops and find pairs 
// Time O(n*n)                 Space o(1) 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int res;
// Special Case   Use long long instead of int to avoid overflow
void countInv(int a[],int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for (int i = 0; i < n1; i++)
    L[i] = a[l+i];
    for (int i = 0; i < n2; i++)
    R[i] = a[m+1+i];
    int i = 0,j = 0,k = l;
    // First count valid pairs 
    while(i < n1 && j < n2)
    {
        long long x = R[j];
        if(L[i] <= 2*x)
        i++;
        else
        {
            res += (n1-i);
            j++;
        }
    }
    // Then use merge function 
    i = 0,j = 0;
    while(i < n1 && j < n2)
    {
        if(L[i] > R[j])
        a[k++] = R[j++];
        else
        a[k++] = L[i++];
    }
    while(i < n1)
    a[k++] = L[i++];
    while(j < n2)
    a[k++] = R[j++];
}
void inversions(int a[],int l,int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        inversions(a,l,m);
        inversions(a,m+1,r);
        countInv(a,l,m,r);
    }
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    res = 0;
    inversions(a,0,N-1);
    cout<<res<<"\n";
    for (int i = 0; i < N; i++)
    cout<<a[i]<<" ";
    return 0;
}