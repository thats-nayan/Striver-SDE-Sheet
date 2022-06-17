
// Rotate a Linked List by K positions

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void print_LL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
Node *insert_end(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}
// Effiicient Approach
// Steps 
// Traverse linked list and find number of nodes (N) and last node end 
// Convert k to less than N using modulo k%=N
// Find k+1 th node from end 
// Do (k+1 th node) ->next  = NULL and make kth node as new head of linked list and also do end->next = head(old) 
Node *rotate_LL(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    Node *end = head;
    int N = 1;
    while (end->next != NULL)
    {
        N++;
        end = end->next;
    }
    k %= N;
    if (k == 0)
        return head;
    int temp = k + 1;
    Node *curr = head;
    while (temp--)
        curr = curr->next;
    Node *start = head;
    while (curr != NULL)
    {
        curr = curr->next;
        start = start->next;
    }
    Node *nhead = start->next;
    start->next = NULL;
    end->next = head;
    return nhead;
}
int main()
{
    int N, K, x;
    cin >> N >> K;
    Node *head = NULL;
    while (N--)
    {
        cin >> x;
        head = insert_end(head, x);
    }
    head = rotate_LL(head, K);
    print_LL(head);
    return 0;
}