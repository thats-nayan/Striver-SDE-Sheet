
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Efficent                         Time O(n)                   Space O(n)
bool balanced(string &s)
{
    stack <char> st;
    int N = s.length();
    for (int i = 0; i < N; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        st.push(s[i]);
        else
        {
            if(st.empty())
            return false;
            if(s[i] == ')')
            {
                if(st.top() != '(')
                return false;
                else
                st.pop();
            }
            else if(s[i] == ']')
            {
                if(st.top() != '[')
                return false;
                else
                st.pop();
            }
            else
            {
                if(st.top() != '{')
                return false;
                else
                st.pop();
            }
        }
    }
    if(st.empty())
    return true;
    return false;
}
int main()
{
    string s;
    cin>>s;
    cout<<balanced(s);
    return 0;
}