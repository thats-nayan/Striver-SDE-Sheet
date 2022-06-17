
// Remove Duplicates From sorted array 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int remove_duplicates(int a[],int N)
{
    int j = 0;
    for (int i = 1; i < N; i++)
    if(a[i] != a[i-1])
    a[j++] = a[i];
    return j;
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    int k = remove_duplicates(a,N);
    for (int i = 0; i < k; i++)
    cout<<a[i]<<" ";
    return 0;
}