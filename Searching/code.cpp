#include <iostream>
using namespace std;

// Binary search function
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoiding overflow

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found, return index
        }

        // If the target is smaller than mid, search in the left half
        if (arr[mid] > target) {
            high = mid - 1;
        }
        // If the target is larger than mid, search in the right half
        else {
            low = mid + 1;
        }
    }

    // If the target is not found
    return -1;
}

int main() {
    // Sample sorted array
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    // Perform binary search
    int result = binarySearch(arr, size, target);

    // Output the result
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
