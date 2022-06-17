
// Clone a Linked List with next and Random Pointer

// Naive Approach
// Create a hashmap of <Node ,Node > and copy the nodes
// Time O(N)                    Space O(N)

// Node *copyRandomList(Node *head)
// {
//     Node *curr = head;
//     unordered_map<Node *, Node *> m;
//     m[NULL] = NULL;
//     while (curr != NULL)
//     {
//         m[curr] = new Node(curr->val);
//         curr = curr->next;
//     }
//     curr = head;
//     while (curr != NULL)
//     {
//         m[curr]->next = m[curr->next];
//         m[curr]->random = m[curr->random];
//         curr = curr->next;
//     }
//     return m[head];
// }

// Efficient Approach

// Time O(n)                    Space O(1)

// Modify the original list
// Org List     1->2->3->4->N
// Mod List     1->1'->2->2'->3->3'->4->4'->N
// Set the random pointers
// Set the next pointers and restore the original list

// Code

// Node *copyRandomList(Node *head)
// {
//     if (head == NULL)
//         return NULL;
//     Node *curr = head;
//     while (curr != NULL)
//     {
//         Node *n = curr->next;
//         Node *ncurr = new Node(curr->val);
//         curr->next = ncurr;
//         ncurr->next = n;
//         curr = n;
//     }
//     curr = head;
//     while (curr != NULL)
//     {
//         if (curr->random != NULL)
//             curr->next->random = curr->random->next;
//         curr = curr->next->next;
//     }
//     Node *nhead = new Node(0);
//     Node *copy = nhead;
//     curr = head;
//     while (curr != NULL)
//     {
//         Node *n = curr->next->next;
//         copy->next = curr->next;
//         copy = copy->next;
//         curr->next = n;
//         curr = n;
//     }
//     return nhead->next;
// }