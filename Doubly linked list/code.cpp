#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next, *prev;

    // constructor
    Node(int x)
    {
        val = x;
        next = prev = nullptr;
    }
};

void print(Node *&head)
{
    Node *t = head;
    while (t != nullptr)
    {
        cout << t->val << " ";
        t = t->next;
    }
}

// insertion
void insertPos(Node *&head, int x, int pos)
{
    Node *newNode = new Node(x);

    if (pos == 1)
    {
        // insert at head
        if (head != nullptr)
        {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node *temp = head;
    // move to the pos-1 th node or last node
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == nullptr)
    {
        // add to the tail
        temp->next = newNode;
        newNode->prev = t;
        return;
    }

    // insert at middle position
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Deletion
void deletePos(Node *&head, int pos)
{
    if (pos == 1)
    {
        // delete head

        Node *del = head;
        head = head->next;
        head->prev = nullptr;
        delete del;
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next->next == nullptr)
    {
        // delete tail
        Node *del = temp->next;
        temp->next = nullptr;
        delete del;
        return;
    }
    // delete middle
    Node *del = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete del;
}

// lb,up,sort,reverse

int main()
{
    // create the first node
    Node *head = new Node(10);
    print(head);
}


struct ListNode {
    int val;
    ListNode *next;
}