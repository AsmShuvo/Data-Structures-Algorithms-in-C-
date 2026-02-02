/*
✅ Problem Statement: Remove Duplicates from a Linked List

You are given the head of a singly linked list.
The linked list may contain duplicate values.

Your task is to remove all duplicate elements such that each value appears only once in the linked list.

After removing duplicates, return the head of the modified linked list.
*/
Node* RemoveDuplicates(Node* head){
    unordered_set<int> seen;

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prev = dummy;
    Node* cur  = head;

    while(cur){
        if(seen.count(cur->val)){
            prev->next = cur->next;
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        } else {
            seen.insert(cur->val);
            prev = cur;
            cur = cur->next;
        }
    }

    Node* ans = dummy->next;
    delete dummy;
    return ans;
}
