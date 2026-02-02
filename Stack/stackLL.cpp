#include <bits/stdc++.h>
using namespace std;

//  print
int sz = 0;

struct Node
{
    int val;
    Node *next;

    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

void push(Node *&top, int value)
{
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    sz++;
}

void pop(Node *&top)
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    Node *nodeToDelete = top;
    top = top->next;
    delete nodeToDelete;
    sz--;
}

int Top(Node *&top)
{
    if (top == NULL)
    {
        cout << "stack is empty" << endl;
        return -1; // not fixed
    }
    return top->val;
}

int Size(Node *&top)
{
    // O(n)
    int sz = 0;
    while (top != NULL)
    {
        sz++;
        top = top->next;
    }
    return sz;
}

void print(Node *&top)
{
    while (top != NULL)
    {
        cout << top->val << " ";
        top = top->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 6);
    push(head, 4);

    pop(head);
    // cout << sz << endl; //optimized

    print(head);
}