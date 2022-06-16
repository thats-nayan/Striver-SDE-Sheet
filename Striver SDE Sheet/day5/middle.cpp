
                        // Middle Of a Linked List 

// Brute Force Method 
// Traverse one time to find number of nodes in linked lists and second time to get middle element 
// Time O(2*N)                  Space O(1)
// Efficient Method 
// Use slow and fast pointer approach 
// Time O(N)                       Space O(1) 
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
Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next == NULL)
    return slow;
    else
    return slow->next;
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
    cout<<middle(head)->data;
    return 0;
}