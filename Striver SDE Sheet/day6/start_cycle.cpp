


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
// Use unordered set to check if same node is trvaersed again or not 
// Time O(N)                            Space O(N) 
// Efficient Approach 
// Use slow and fast pointer approach       
// Ffloyd Cycle Detection Algo 
// Time O(N)                        Space O(1)
Node *start_cycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        break;
    }
    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
int main()
{
    
    return 0;
}