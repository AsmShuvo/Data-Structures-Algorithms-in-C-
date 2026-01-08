// A set in C++ is an associative container that stores unique elements in a sorted order. It automatically handles duplicate entries by not allowing duplicates to be added.

// Key Features of a Set:

// Sorted Order: The elements in the set are automatically sorted in ascending order (or as per the specified comparator).

// Unique Elements: No duplicate elements are allowed.

// Efficient Operations: Operations like insertion, deletion, and search are performed in O(log n) time, thanks to the underlying balanced binary search tree.

// Basic Operations:

// Insert: Adds an element to the set. Duplicates are not allowed.

// Find: Searches for an element. Returns an iterator to the element if found, or end() if not found.

// Erase: Removes an element from the set.

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create an empty set
    set<int> s;
    
    // Insert elements
    s.insert(6);
    s.insert(3);
    s.insert(31);
    s.insert(311);
    s.insert(2);
    s.insert(6); // won't be added (duplicate)
    s.insert(1);
    s.insert(-12);

    // Traverse and print the set (using range-based for loop)
    cout << "Set elements: ";
    for (int x : s) {
        cout << x << " ";  // Output: -12 1 2 3 6 31 311
    }
    cout << endl;

    // Find an element (e.g., 2)
    int x = 2;
    auto ptr = s.find(x);
    if (ptr == s.end()) {
        cout << x << " not found" << endl;
    } else {
        int dis = distance(s.begin(), ptr);
        cout << x << " found at position: " << dis << endl;
    }

    // Erase the first element
    s.erase(s.begin());
    cout << "After deleting first element: ";
    for (int x : s) {
        cout << x << " ";  // Output: 1 2 3 6 31 311
    }
    cout << endl;

    // Erase the last element
    s.erase(--s.end());
    cout << "After deleting last element: ";
    for (int x : s) {
        cout << x << " ";  // Output: 1 2 3 6 31
    }
    cout << endl;

    // Erase a specific element (e.g., 3)
    s.erase(3);
    cout << "After deleting 3: ";
    for (int x : s) {
        cout << x << " ";  // Output: 1 2 6 31
    }
    cout << endl;

    // Check if an element (e.g., 2) is present
    auto itr = s.find(2);
    if (itr == s.end()) {
        cout << "2 not found" << endl;  // Output: 2 not found
    } else {
        s.erase(itr);  // Erase element using iterator
    }
    
    // Print set after deletion
    cout << "After deleting 2: ";
    for (int x : s) {
        cout << x << " ";  // Output: 1 6 31
    }
    cout << endl;
}
