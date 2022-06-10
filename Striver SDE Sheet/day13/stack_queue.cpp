
                        // Implement Stack Using  Queues 

// Method 1 
// Using 2 Queues 
// Observation 
// Whenever we add a new element we have to bring it to front of queue 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// class MyStack {
// public:
//     queue <int> q1,q2;
//     void push(int x) {
//         q2.push(x);
//         while(q1.empty() == false)
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1,q2);
//     }
//     int pop() {
//         q1.pop();   
//     }
//     int top() {
//         return q1.front();
//     }
//     bool empty() {
//         return q1.size() == 0;   
//     }
// };

// Method 2 
// Using single queue 
// To bring recently added element to front of  queue we add it to queue and remove starting elements and insert them again  
class MyStack {
public:
    queue <int> q;
    void push(int x) {
        int count = q.size();
        q.push(x);
        for (int i = 0; i < count; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
int main()
{
    
    return 0;
}