
                        // Intersection of Two Y shaped Linked Lists 



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
// Brute Force 
// Run 2 nested loops               Time O(M*N)         Space O(1)

// Better Method 
// Use hashing                      Time O(M+N)         Space O(min(M,N))

// More better method (My unique approach)
// Connect tail of one linked list with head of other 
// This will create cycle with intersection node as start of cycle 
// Then use Flloyd cycle detection algo to find start of cycle 
// Time O(M+N)                  Space O(1)      nut modifies the linked list and big code 

// Efficient Method
// Find length od both linked list and move pointer of bigger length by difference of both linked list  
// and then compare node by node 
// Time O(M+N)                  Space o(1)
Node *intersection(Node *head1,Node *head2)
{
    int N = 0,M = 0;
    Node *curr1 = head1,*curr2 = head2;
    while(curr1 != NULL)
    {
        N++;
        curr1 = curr1->next;
    }
    while(curr2 != NULL)
    {
        M++;
        curr2 = curr2->next;
    }
    if(N > M)
    {
        curr1 = head1;
        int k = N-M;
        while(k--)
        curr1 = curr1->next;
        curr2 = head2;
        while(curr1 != NULL)
        {
            if(curr1 == curr2)
            return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    else
    {
        curr2 = head2;
        int k = M-N;
        while(k--)
        curr2 = curr2->next;
        curr1 = head1;
        while(curr1 != NULL)
        {
            if(curr1 == curr2)
            return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
}
int main()
{
    int N,M,x;
    cin>>N>>M;
    Node *head1 = NULL,*head2 = NULL;
    while(N--)
    {
        cin>>x;
        head1 = insert_end(head1,x);
    }
    while(M--)
    {
        cin>>x;
        head2 = insert_end(head2,x);
    }
    cout<<intersection(head1,head2)->data<<"\n";
    return 0;
}