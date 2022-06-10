
                        // Next Greater Element GFG
                        
// Brute Force 
// Run 2 nested loops and find next greater 
// Time O(N*N)                                      Space O(1)

// Efficient Method         Use stack to keep track of next greater      
// Time O(N)                   Space o(N)
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// vector <int> next_greater(vector <int> &a,int N)
// {
//     stack <int> st;
//     for (int i = N-1; i >= 0; i--)
//     {
//         while(st.empty() == false && st.top() <= a[i])
//         st.pop();
//         int temp = a[i];
//         if(st.empty())
//         a[i] = -1;
//         else
//         a[i] = st.top();
//         st.push(temp);
//     }
//     return a;
// }
// int main()
// {
//     int N;
//     cin>>N;
//     vector <int> a(N);
//     for (int i = 0; i < N; i++)
//     cin>>a[i];
//     vector <int> ans = next_greater(a,N);
//     for(auto x: ans)
//     cout<<x<<" ";
//     return 0;
// }

                                // Next Greater I/II 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// vector <int> next_greater(vector <int> &a,vector <int> &b)
// {
//     int N = a.size();
//     int M = b.size();
//     stack <int> s;
//     unordered_map <int,int> m;
//     for (int i = M-1; i >= 0; i--)
//     {
//         while(s.empty() == false && s.top() <= b[i])
//         s.pop();
//         if(s.empty())
//         m[b[i]] = -1;
//         else
//         m[b[i]] = s.top();
//         s.push(b[i]);
//     }
//     for (int i = 0; i < N; i++)
//     a[i] = m[a[i]];
//     return a;
// }
vector <int> next_greater2(vector <int> &a)
{
    int N = a.size();
    vector <int> ans(N);
    stack <int> s;
    for (int i = N-1; i >= 0; i--)
    {
        while(s.empty() == false && s.top() <= a[i])
        s.pop();
        if(s.empty())
        ans[i] = INT32_MIN;
        else
        ans[i] = s.top();
        s.push(a[i]);
    }
    for (int i = N - 1; i >= 0 && s.empty() == false; i--)
    {
        if(ans[i] == INT32_MIN)
        {
            while(s.empty() == false && s.top() <= a[i])
            s.pop();
            if(s.empty())
            ans[i] = INT32_MIN;
            else
            ans[i] = s.top();
        }
    }
    for (int i = 0; i < N; i++)
    if(ans[i] == INT32_MIN)
    ans[i] = -1;
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector <int> a(N);
    for (int i = 0; i < N; i++)
    cin>>a[i];
    vector <int> ans = next_greater2(a);
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}