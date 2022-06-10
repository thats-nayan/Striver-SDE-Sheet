
                        // Palindromic Partition 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string &s)
{
    int N = s.length();
    for (int i = 0; i < N/2; i++)
    if(s[i] != s[N-1-i])
    return false;
    return true;
}
// Best Way to Generate Partitions 
// Time O(2^n * k * (n/2))                                  Space O(k*x) 
// where k is avg length of list of p-alindromes and x is no of palindromes 
void recursion(string &s,int i,int N,vector <string> temp,vector <vector<string>> &ans)
{
    if(i == N)
    ans.push_back(temp);
    else
    {
        string res ;
        for (int j = i; j < N; j++)
        {
            res.push_back(s[j]);
            if(ispalindrome(res))
            {
                temp.push_back(res);
                recursion(s,j+1,N,temp,ans);
                temp.pop_back();
            }
        }
    }
}
vector <vector<string>> palindrome(string s)
{
    int N = s.length();
    vector <vector<string>> ans;
    vector <string> temp;
    recursion(s,0,N,temp,ans);
    return ans;
}
int main()
{
    string s;
    cin>>s;
    vector <vector<string>> ans = palindrome(s);
    for(auto x: ans)
    {
        for (int i = 0; i < x.size(); i++)
        cout<<x[i]<<" ";
        cout<<"\n";
    }
    return 0;
}