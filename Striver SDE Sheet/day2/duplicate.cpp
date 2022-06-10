
// Brute Force 
// Method 1 
// Sort Array and then find elelemet which apears more than once 
// Time O(NlogN)               Space O(1)

// Method 2 
// Create Hash Table and check frequency is graeter than 1 
// Time O(n)           Space O(n) 

// Best Approach 
// Use SlowFast Approach of Linked List to find duplicate element 
// Time O(n)            Space O(1)

#include<iostream>
using namespace std;
int duplicate(int a[],int N)
{
    int slow = 0,fast = 0;
    do
    {
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);
    fast = 0;
    while(slow != fast)
    {
        slow = a[slow];
        fast = a[fast];
    }
    return slow;
}
int main()
{
    int N;
    cin>>N;
    int a[N+1];
    for (int i = 0; i <= N; i++)
    cin>>a[i];
    cout<<duplicate(a,N);
    return 0;
}