
                    // Count Inversions in Array 

// Brute Force 
// Run nested loops and count inversions 
// Time O(N*N)                      Space O(1)
// Efficient Approach 
// Use merge sort to sort array 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int res = 0;
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
    while(i < n1 && j < n2)
    {
        if(L[i] > R[j])
        {
            res += (n1-i);
            a[k++] = R[j++];
        }
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
    for(int i = 0 ; i < N ; i++)
    cin>>a[i];
    inversions(a,0,N-1);
    cout<<res<<"\n";
    return 0;
}