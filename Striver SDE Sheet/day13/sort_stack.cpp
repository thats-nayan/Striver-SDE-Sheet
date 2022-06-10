
                            // Sort a Stack 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Sorting Using temporary Stack
// Tine O(n*n)                                  Space O(n)
void sort_stack(stack <int> &s)
{
    stack <int> temp;
    while(s.empty()== false)
    {
        int x = s.top();
        s.pop();
        while(temp.empty()== false && temp.top() < x)
        {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(x);
    }
    while(temp.empty() == false)
    {
        s.push(temp.top());
        temp.pop();
    }
}
// Sorting a Stack Using Recursion 
int main()
{
    int N,x;
    cin>>N;
    stack <int> s;
    while(N--)
    {
        cin>>x;
        s.push(x);
    }
    sort_stack(s);
    while(s.empty() == false)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}