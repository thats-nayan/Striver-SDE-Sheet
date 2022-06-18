
// Flatten Linked List

// Naive Approach
// Use Merge Funnction of merge sort N times 

// Time O(N*N*M)                    Space O(1)
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *bottom;
    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
Node *merge(Node *list1, Node *list2)
{
    Node *curr1 = list1;
    Node *curr2 = list2;
    Node *head = NULL, *ans = NULL;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data < curr2->data)
        {
            if (head == NULL)
            {
                head = curr1;
                ans = curr1;
            }
            else
            {
                ans->bottom = curr1;
                ans = curr1;
            }
            curr1 = curr1->bottom;
        }
        else
        {
            if (head == NULL)
            {
                head = curr2;
                ans = curr2;
            }
            else
            {
                ans->bottom = curr2;
                ans = curr2;
            }
            curr2 = curr2->bottom;
        }
    }
    while (curr1 != NULL)
    {
        ans->bottom = curr1;
        ans = curr1;
        curr1 = curr1->bottom;
    }
    while (curr2 != NULL)
    {
        ans->bottom = curr2;
        ans = curr2;
        curr2 = curr2->bottom;
    }
    return head;
}
// Node *flatten(Node *head)
// {
//     if (head == NULL || head->next == NULL)
//         return head;
//     Node *list1 = head;
//     Node *list2 = head->next;
//     while (list2 != NULL)
//     {
//         list1 = merge(list1, list2);
//         list2 = list2->next;
//     }
//     return list1;
// }
// Efficient Approach 
// Use same method as merge k sorted linked list using priority queue 
// Time O(N*M*logN)                     Space O(N)
Node *flatten(Node *head)
{
    priority_queue <pair<int,Node *>,vector<pair<int,Node *>>,greater<pair<int,Node *>>> pq;
    Node *curr = head;
    while(curr != NULL)
    {
        pq.push({curr->data,curr});
        curr = curr->next;
    }
    
}
int main()
{

    return 0;
}
