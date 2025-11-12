#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;

    // constructor
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void printLL(Node *&head)
{
    // creating a temp ptr to traverse
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
// **************INSERTION ************************
// head
// void insertAtHead(Node *head, int val)
// {
//     // creating the new node
//     Node *newNode = new Node(val); // 6
//     newNode->next = head;
//     head = newNode;
// }
// void insertAtPos(Node *&head, int val, int pos)
// {
//     // creating the new node
//     Node *newNode = new Node(val);
//     // taking a temp ptr to traverse the LL
//     Node *temp = head;
//     int cnt = 0;
//     while (cnt <= pos - 2)
//     {
//         temp = temp->next;
//         cnt++;
//     }
//     newNode->next = temp->next;
//     temp->next = newNode;
// }
// // tail
// void insertNodeTail(Node *&head, int val)
// {
//     // creating the new node
//     Node *newNode = new Node(val);
//     // taking a temp ptr to traverse the LL
//     Node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     // temp is at the last node
//     temp->next = newNode;
// }
// INSERT AT ALL POSITIONS
void insertNode(Node *&head, int val, int pos)
{
    Node *newNode = new Node(val);

    // Case 1: Insert at beginning (pos = 1)
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    int count = 1;

    // Traverse to (pos - 1)th node
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    // If position is out of range or inserting at end
    if (temp == NULL)
    {
        cout << "Position out of range\n";
        delete newNode;
        return;
    }

    // Case 2 & 3: Insert at middle or end
    newNode->next = temp->next;
    temp->next = newNode;
}

/***********************DELETION *************/

void deleteNode(Node *&head, int pos)
{
    if (pos == 1)
    {
        // head
        Node *t = head;
        head = head->next;
        delete t;
        return;
    }

    // deletemiddle
    Node *t = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        t = t->next;
        cnt++;
    }
    Node *nodeToDelete = t->next;
    t->next = nodeToDelete->next;
    delete nodeToDelete;
}

int main()
{
    Node *head = new Node(1);
    // cout<<head->val<<endl;

    // printing second element:
    insertNode(head, 2, 2);
    insertNode(head, 3, 3);
    insertNode(head, 4, 4);
    insertNode(head, 5, 5);
    insertNode(head, 6, 6);
    // printing the LL
    cout << "Initial LL: ";
    printLL(head);

    // insert at head
    // insertAtHead(head, 6);
    // printLL(head);
    insertNode(head, 8, 1);
    printLL(head);

    // deleting the head
    cout<<"After deletion: ";
    deleteNode(head, 1);
    printLL(head);
    deleteNode(head, 6);
    printLL(head);
    deleteNode(head, 3);
    printLL(head);

    // deleteing the head
    // dele

    return 0;
}

/*
time complexity:
    inserting: O(n)
    printing: O(n)
*/
