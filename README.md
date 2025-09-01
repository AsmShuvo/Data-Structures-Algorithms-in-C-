# 📘 DSA Topic List

A structured list of **Data Structures and Algorithms (DSA)** topics to practice and master.  
This checklist helps in tracking progress while preparing for coding interviews and competitive programming.

---


## 📂 Searching
- [ ] Linear Search  
- [ ] Binary Search  
- [ ] Ternary Search  

## 📂 Sorting
- [ ] Bubble Sort  
- [ ] Selection Sort  
- [ ] Insertion Sort  
- [ ] Merge Sort  
- [ ] Quick Sort  
- [ ] Counting Sort  
- [ ] Radix Sort  
- [ ] Bucket Sort  

## 📂 Recursion
- [ ] Recursion Basics  

## 📂 Linked List
- [ ] Insertion, Deletion, Traversal Operations  
- [ ] Searching Operations  
- [ ] Doubly Linked List  
- [ ] Circular Linked List  

## 📂 Stack
- [ ] Push and Pop Operations  
- [ ] Stack using Array  
- [ ] Stack using Linked List  

## 📂 Queue
- [ ] Enqueue and Dequeue Operations  
- [ ] Queue using Array  
- [ ] Queue using Linked List  
- [ ] Stack using Queue  
- [ ] Circular Queue  
- [ ] Priority Queue  
- [ ] Double Ended Queue  

## 📂 Trees
- [ ] Inorder Traversal  
- [ ] Preorder Traversal  
- [ ] Postorder Traversal  
- [ ] Binary Tree  
- [ ] Types of Binary Tree  

## 📂 Binary Search Tree
- [ ] Search, Insertion, Deletion Operations  
- [ ] AVL Tree  
- [ ] RB Tree  
- [ ] B-Tree  

## 📂 Heaps
- [ ] Binary Heap  
  - [ ] Insertion, Delete Operations  
  - [ ] Heapify  
- [ ] Heapsort  

## 📂 Maps and Hashtable
- [ ] Maps and Hashtable Problems  

## 📂 Graphs
- [ ] Adjacency List  
- [ ] Adjacency Matrix  
- [ ] Breadth-First Search Algorithms  
- [ ] Depth-First Search Algorithms  
- [ ] Topological Sorting  
- [ ] Prim’s Algorithm  
- [ ] Kruskal’s Algorithm  
- [ ] Dijkstra’s Algorithm  

## 📂 Tries
- [ ] Standard Trie  
- [ ] Compressed Trie  
- [ ] Suffix Trie  

## 📂 Advanced Topics
- [ ] Dynamic Programming   
- [ ] Backtracking Algorithms  
- [ ] Disjoint Set  

---

✅ Use this list to track progress: Check off `[x]` once you’ve completed a topic!  


# Heap Data Structure Notes

## Overview
- A *Heap* is a complete binary tree data structure.
- It is used in priority queues.

### Types of Heaps
- *Min Heap*: Every child value must be greater than or equal to its parent's value.
- *Max Heap*: Every child value must be less than or equal to its parent's value.

## Operations and Time Complexity
### Insertion
- *Process*: Insert a new value and adjust the heap.
- *Time Complexity*: 
  - Worst Case: O(log n)
  - Best Case: O(1)

### Deletion
- *Process*: Remove the last element and move it to the root, then adjust the heap.
- *Time Complexity*: O(log n)

### Searching
- *Time Complexity*: O(n)

## Example: Max Heap Insertion
- Initial Heap: [50, 30, 20, 15, 10, 8, 16]
- Insert 60:
  - After Insertion and Adjustment: [60, 30, 20, 15, 10, 8, 16, 50]

## Example: Deletion from Max Heap
- Initial Heap: [50, 30, 20, 15, 10, 8, 16]
- Delete 50:
  - Move last element (16) to root.
  - Adjust Heap: [30, 15, 20, 8, 10, 16]

## Notes
- Heaps are efficient for priority queue implementations.
- Adjusting the heap after insertion or deletion takes O(log n) time due to the height of the tree.
- Searching in a heap is linear O(n) as it is not designed for search operations.