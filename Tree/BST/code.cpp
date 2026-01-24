// property: left child < parent < right child
// BST is needed to implement AVL tree, Red-Black tree,
// BST is needed to implement set, map in STL
// worst time complexity of search, insert, delete: O(log n)
// Inorder traversal of a BST gives sorted order of elements.
// Average height: O(log n) (for balanced BST).
// Worst case height: O(n) (when tree becomes skewed).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
// The worst-case time complexity of insert operations is O(h)
// average case time complexity: O(log n)
Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// The worst-case time complexity of search operations is O(h)
// average case time complexity: O(log n)
bool search(Node *root, int val)
{
    if (root == NULL)
        return false;
    if (root->data == val)
        return true;
    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

void deleteNode(Node *root, int val)
{
    if (root == NULL)
        return;
    if (val < root->data)
        deleteNode(root->left, val);
    else if (val > root->data)
        deleteNode(root->right, val);
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            root = temp;
        }
        else
        {
            // VVI****
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node *temp = root->right;
            while (temp && temp->left != NULL)
                temp = temp->left;
            // Copy the inorder successor's content to this node
            root->data = temp->data;
            // *** Remember to delete from right subtree
            deleteNode(root->right, temp->data);
        }
    }
}