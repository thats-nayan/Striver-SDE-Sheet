
// Print all unique quadraplets in array whith sum X 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force 
// Sort the array and apply 3 pointer and binary search 
// Time O(N*N*N*logN)                           Space O(N)
// Efficient Sort first and then Run 2 nested loops and apply 2 pointer approach  
// Time o(n*n*n)                                Space O(1)   
vector <vector<int>> four_sum(vector <int> &a,int X)
{
    int N = a.size();
    sort(a.begin(),a.end());
    vector <vector<int>> ans;
    for (int i = 0; i < N-3; i++)
    {
        if(i > 0 && a[i] == a[i-1])
        continue;
        for (int j = i+1; j < N-2; j++)
        {
            if(j > i+1 && a[j] == a[j-1])
            continue;
            // cout<<"i = "<<i<<" j = "<<j<<"\n";
            int l = j+1;
            int r = N-1;
            while(l < r)
            {
                if(a[i]+a[j]+a[l]+a[r] == X)
                {
                    ans.push_back({a[i],a[j],a[l],a[r]});
                    int temp1 = l;
                    while(l < N && a[l] == a[temp1])
                    l++;
                    temp1 = r;
                    while(r >= 0 && a[r] == a[temp1])
                    r--;
                }
                else if(a[i]+a[j]+a[l]+a[r] < X)
                l++;
                else
                r--;
            }
        }
    }
    return ans;
}
int main()
{
    int N,X;
    cin>>N>>X;
    vector <int> a(N);
    for (int i = 0; i < N; i++)
    cin>>a[i];
    vector <vector<int>> ans = four_sum(a,X);
    for(auto x: ans)
    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<"\n";
    return 0;
}