
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
// Method 1             Sort Araray             Time O(nlogn)           Space O(n)
// Method 2            Count 0,1,2 and make array           Time O(N) but 2 traversals          Space O(1)
// Method 3            Dutch National Flag Algo                Time O(n) in 1 trversal          Space O(1)
void sort_012(vector <int> &v)
{   
    int N = v.size();
    int low = 0,high = N-1,mid = 0;
    while(mid <= high)
    {   
        if(v[mid] == 0)
        swap(v[low++],v[mid++]);
        else if(v[mid] == 2)
        swap(v[mid],v[high--]);
        else
        mid++;
    }
}
int main()
{
    int N;
    cin>>N;
    vector <int> v(N);
    for (int i = 0; i < N; i++)
    cin>>v[i];
    sort_012(v);
    for(auto x:v)
    cout<<x<<" ";
    return 0;
}