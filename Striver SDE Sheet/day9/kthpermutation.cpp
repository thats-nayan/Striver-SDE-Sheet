                // kth Permutation 

// Brute Force 
// Generate All Permutations of a string 
// and sort the vector of strings nand print kth string 
// Time O(n!log(n!))                         Space O(n!) 

// Better Approach 

// Create array and sort it and use next permutation k times 
// Time O(n!)                               Space O(n)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void next_permutation(vector <int> &v)
{
    int N = v.size();
    bool found = false;
    for (int i = N-1; i >= 1; i--)
    {
        if(v[i-1] < v[i])
        {
            found = true;
            for (int j = N- 1; j >= 0; j--)
            {
                if(v[j] > v[i-1])
                {
                    // cout<<"v(i-1) = "<<v[i-1]<<" v(j) = "<<v[j]<<"\n";
                    swap(v[i-1],v[j]);
                    break;
                }
            }
            reverse(v.begin()+i,v.end());
            break;
        }
    }
    if(found == false)
    reverse(v.begin(),v.end());
}
// string kth_permutation(int N,int K)
// {
//     vector <int> a(N);
//     for (int i = 0; i < N; i++)
//     a[i] = i+1;
//     while(K != 1)
//     {
//         next_permutation(a);
//         K--;
//     }
//     string ans;
//     for (int i = 0; i <  N; i++)
//     ans.push_back(a[i]+'0');
//     return ans;
// }
// Efficuent Approach 
// Time O(N*N)                 Space O(1)
string kth_permutation(int N,int K)
{
    K--;
    string ans;
    set <char> s;
    for (int i = 0; i < N; i++)
    s.insert(i+'0'+1);
    int fac = 1;
    for(int i = 2; i <= N-1 ; i++)
    fac *= i;
    while(ans.length() < N)
    {
        if(K == 0)
        {
            for(auto x: s)
            ans.push_back(x);
        }
        else
        {
            int y = K/fac;
            for(auto x: s)
            {
                if(y == 0)
                {
                    ans.push_back(x);
                    s.erase(x);
                    K %= fac;
                    fac /= (s.size());
                    // cout<<"ans = "<<ans<<" K = "<<K<<" fac = "<<fac<<"\n";
                    break;
                }
                else
                y--;
            }
        }
    }
    return ans;
}
int main()
{
    int N,K;
    cin>>N>>K;
    cout<<kth_permutation(N,K);
    return 0;
}