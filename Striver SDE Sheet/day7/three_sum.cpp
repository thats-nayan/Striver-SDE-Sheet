
                        // Three Sum 

// Count unique triplets with sum zero 
// Brute Force 
// Run 3 nested loops and put all triplets in hash set and return size of hash set 
// Time O(n*n*n log m)                            Space O(m)
// where m is no of unique triplets 

// Efficient Method Use hashing 
// Run a loop and store ecah element with frequency in hash map 
// Then run 2 nested loops and for the 3rd elelent in triplet use frequency of that element in hashmap to count 

// Best Approach 
// Sort the array and use 2 pointer approach            
// Time O(n*n)          Space o(1)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector <vector<int>> triplets(int a[],int N)
{
    vector <vector<int>> ans;
    if(N < 3)
    return ans;
    else
    {
        sort(a,a+N);
        for (int i = 0; i < N-2; i++)
        {
            if(i > 0 && a[i] == a[i-1])
            continue;
            int l = i+1,r = N-1;
            while (l < r)
            {
                if(a[l]+a[r]+a[i] == 0) 
                {
                    ans.push_back({a[i],a[l],a[r]});
                    int temp = l;
                    while(l < N && a[temp] == a[l])
                    l++;
                    temp = r;
                    while(r > l && a[temp] == a[r])
                    r--;
                }  
                else if(a[l]+a[r]+a[i] > 0)
                r--;
                else
                l++;
            }
        }
        return ans;
    }
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    vector <vector<int>> ans = triplets(a,N);
    for(auto x: ans)
    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
    return 0;
}