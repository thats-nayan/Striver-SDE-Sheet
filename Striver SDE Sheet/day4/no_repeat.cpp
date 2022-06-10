
                    // Find Longest Substring Without Repeating Characters 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force 
// Traverse all substrings and check whether it contains all distinct charcaters 
// Tine O(n*n)                 Space O(n)

// Efficient Approach 
// Use 2 pointers incremenr right pointer from 0 to N and use hashmap to find length of longest subsring with no repeat
// ending at r 
// Time O(N)                       Space O(N) 
int no_repeat(string &s)
{
    int N = s.length();
    int l = 0,r = 0;
    unordered_map <char,int> m;
    int ans = 0;
    while(r < N)
    {
        if(m.find(s[r]) != m.end())
        {
            if(m[s[r]] >= l)
            l = m[s[r]]+1;
        }
        m[s[r]] = r;
        ans = max(ans,r-l+1);
        r++;
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<no_repeat(s)<<"\n";
    return 0;
}