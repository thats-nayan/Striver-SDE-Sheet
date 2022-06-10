
                    // Find median in  a N X M row wise sorted matrix  (N*M is odd)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force 
// Put all matrix values in a array , sort the array and return middlemost element 
// Tine O(N*M log (N*M))                    Space O(1) 
// Efficient Method 
// For every number between MIN and Max find how many numbers are less than equal to and check if it is median 
// Time O(log2(MAX-MIN)*N*log(M))                   Space O(1)

int median(vector <vector<int>> &v)
{
    int N = v.size();
    int M = v[0].size();
    int l = 1e9+1,r = -1;
    for (int i = 0; i < N; i++)
    {
        l = min(l,v[i][0]);
        r = max(r,v[i][M-1]);
    }
    int ans;
    while(l <= r)
    {
        int m = (l+r)/2;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if(m >= v[i][M-1])
            sum += M;
            else if(m < v[i][0])
            sum += 0;
            else
            {
                int low = 0,high = M-1,mid,res;
                while(low <= high)
                {
                    mid = (low+high)/2;
                    if(v[i][mid] > m)
                    high = mid-1;
                    else
                    {
                        res = mid;
                        low = mid+1;
                    }
                }
                sum += res+1;
            }
            // cout<<"m = "<<m<<" sum = "<<sum<<"\n";
        }
        if(sum <= (N*M)/2)
        l = m+1;
        else
        {
            ans = m;
            r = m-1;
        }
    }
    int res = 1e9;
    for (int i = 0; i < N; i++)
    {
        int low = 0,high = M-1,mid;
        int k;
        if(v[i][high] >= ans)
        {   
            while(low <= high)
            {
                mid = (low+high)/2;
                if(v[i][mid] >= ans)
                {
                    k = v[i][mid];
                    high = mid-1;
                }
                else
                low = mid+1;
            }
            res = min(res,k);
        }   
    }
    return res;
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector <vector<int>> v(N,vector <int> (M,-1));
    for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    cin>>v[i][j];
    cout<<median(v);
    return 0;
}