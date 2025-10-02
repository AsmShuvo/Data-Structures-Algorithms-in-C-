#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;

    // constructor
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void printLL(Node* head){
    // creating a temp ptr to traverse
    Node* temp = head;
    while (temp!=NULL)      
    {
        cout<<temp->val<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

void insertNode(Node* &head, int val){
    // creating the new node
    Node* newNode = new Node(val);
    // taking a temp ptr to traverse the LL
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    // temp is at the last node
    temp->next = newNode;
}

int main(){
    Node* head = new Node(1);
    // cout<<head->val<<endl;

    // printing second element:
    insertNode(head, 2);
    // cout<<head->next<<endl;
    // cout<<head->next->val<<endl;
    // cout<<head->next->next<<endl;

    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    //printing the LL
    printLL(head);

}

/*
time complexity: 
    inserting: O(n)
    printing: O(n)
*/