
// Merge 2 Sorted Linekd Lists

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
// Just use normal merge function of merge sort
// Time O(M+N)                  Space O(1)
Node *merge_LL(Node *head1, Node *head2)
{
    Node *head = NULL, *curr = NULL;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *curr1 = head1, *curr2 = head2;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data < curr2->data)
        {
            if (head == NULL)
            {
                head = curr1;
                curr = curr1;
            }
            else
            {
                curr->next = curr1;
                curr = curr1;
            }
            curr1 = curr1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = curr2;
                curr = curr2;
            }
            else
            {
                curr->next = curr2;
                curr = curr2;
            }
            curr2 = curr2->next;
        }
    }
    while (curr1 != NULL)
    {
        curr->next = curr1;
        curr = curr1;
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        curr->next = curr2;
        curr = curr2;
        curr2 = curr2->next;
    }
    return head;
}
int main()
{
    int N, M, x;
    cin >> N >> M;
    Node *head1 = NULL, *head2 = NULL;
    while (N--)
    {
        cin >> x;
        head1 = insert_end(head1, x);
    }
    while (M--)
    {
        cin >> x;
        head2 = insert_end(head2, x);
    }
    Node *head = merge_LL(head1, head2);
    print_LL(head);
    return 0;
}