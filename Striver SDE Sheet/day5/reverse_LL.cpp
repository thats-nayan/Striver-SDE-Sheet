// Linked Lists

#include <iostream>
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
// Method 
// Maintain 3 pointers prev,curr and next change link of curr from next to prev and move curr to next
//  and prev to curr        
//  Time O(N)           Space O(1)

// Iterative Method 
Node *reverse_LL(Node *head)
{
    Node *prev = NULL,*curr = head,*n;
    while(curr != NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
}
// Recursive Method 
Node *reverse_rec(Node *head,Node *prev)
{
    if(head == NULL)
    return prev;
    else
    {
        Node *n = head->next;
        head->next = prev;
        return reverse_rec(n,head);
    }
}
int main()
{
    int N,x;
    cin>>N;
    Node *head = NULL;
    while(N--)
    {
        cin>>x;
        head = insert_end(head,x);
    }
    // head = reverse_LL(head);
    head = reverse_rec(head,NULL);
    print_LL(head);
    return 0;
}