#include <bits/stdc++.h>
using namespace std;

struct Node
{
    // 1 val, 2 pointers -->
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

void insert(int val, int pos, Node *&head)
{
    // create a node with val
    Node *newNode = new Node(val);
    // empty
    if (head == NULL)
    {
        if (pos > 0)
        {
            cout << "The list is empty, so pos should be 0";
        }
        else
        {
            head = newNode;
        }
        return;
    }

    // insert at front
    if (pos == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        // head must be at front
        head = newNode;
        return;
    }

    // back or middle
    Node *temp = head;
    int cnt = 0;
    // traverse to pos-1
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // pick the next value of temp
    Node *temp2 = temp->next;
    if (temp2 == NULL)
    {
        // insert at tail
        temp->next = newNode;
        newNode->prev = temp;
    }
    else
    {
        // insert to middle
        temp->next = newNode;
        newNode->prev = temp;

        temp2->prev = newNode;
        newNode->next = temp2;
    }
}

void deleteNode(int pos, Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty, nothing to delete";
        return;
    }
    // delete Head Node
    Node *temp = head;
    if (pos == 0)
    {
        head = head->next;
        delete temp;
        return;
    }

    int cnt = 0;
    while (cnt < pos)
    {
        temp = temp->next;
        cnt++;
    }
    // the temp is now at the node to delete
    Node *prevNode = temp->prev;
    Node *nextNode = temp->next;
    if (nextNode == NULL)
    {
        // delete tail
        prevNode->next = NULL;
        delete temp;
        return;
    }
    // delete from middle
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete temp;
}

int main()
{
    Node *head = NULL;
    insert(12, 0, head);
    insert(13, 1, head);
    insert(14, 2, head);
    insert(11, 0, head);
    insert(34, 0, head);
    insert(43, 0, head);
    insert(69, 0, head);
    insert(2, 2, head);
    cout << "before delete: ";
    print(head);
    // Delete
    // delete head
    cout << "\nafter delete: " << endl;
    deleteNode(0, head);
    deleteNode(6, head);
    deleteNode(3, head);

    print(head);
}
