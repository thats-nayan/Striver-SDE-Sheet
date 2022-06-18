


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
// Brute Force Method 
// Store Linked List in Array and  use Normal Method 
// Time O(N)                    Space O(n) 

// Efficient Method 
// Find middle node 
// Reverse linked list to right of middle node 
// Compare each node one by one 
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
bool ispalindrome(Node *head)
{
    if(head == NULL || head->next == NULL)
    return true;
    Node *slow = head;
    Node *fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse_LL(slow->next);
    Node *curr = head;
    slow = slow->next;
    while(slow != NULL)
    {
        if(slow->data != curr->data)
        return false;
        slow = slow->next;
        curr = curr->next;
    }
    return true;
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
    cout<<ispalindrome(head);
    return 0;
}