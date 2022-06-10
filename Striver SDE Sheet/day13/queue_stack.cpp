
                        // Implement Queue Using Stack 

// Method 1   Using 2 stacks
// Similar as implementing stack using 2 queues 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack <int> s1,s2;
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        while(s1.empty() == false)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int x  = s2.top();
        s2.pop();
        while(s2.empty() == false)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    int peek() {
        while(s1.empty() == false)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int x  = s2.top();
        while(s2.empty() == false)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    bool empty() {
        return s1.empty();
    }
};

int main()
{
    
    return 0;
}