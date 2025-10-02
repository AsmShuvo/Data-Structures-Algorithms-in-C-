#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) {
        int isSwapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwapped=1;
            }
        }
        // if(isSwapped==0) break;
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}


// Time comp: O(n^2) Best case(sorted array): O(n) optimized