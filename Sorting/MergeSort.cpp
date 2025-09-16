#include <bits/stdc++.h>
using namespace std;

void Merge(int a[], int l, int mid, int r)
{
    int sz1 = mid - l + 1, sz2 = r - mid;
    int L[sz1], R[sz2];
    for (int i = 0; i < sz1; i++)
        L[i] = a[l + i];
    for (int i = 0; i < sz2; i++)
        R[i] = a[mid + 1 + i];
    int i = 0, j = 0, k = l; // starting indexes of L , R and main array
    while (i < sz1 && j < sz2)
    {
        if (L[i] < R[j])
        {
            a[k] = L[i];
            i++;
            k++;
        }
        else
        {
            a[k] = R[j];
            j++;
            k++;
        }
    }
    // if i do not reach the last of L
    if(i<sz1){
        while (i<sz1)
        {
            a[k]=L[i];
            i++; k++;
        }
    }
    // // if j do not reach the last of R
    if(j<sz2){
        while (j<sz2)
        {
            a[k]=R[j];
            j++; k++;
        }
    }
}

void MergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);
        Merge(a, l, mid, r);
    }
}

int main()
{
    int arr[] = {4, 2, 5, 2, 1};
    MergeSort(arr, 0, 4);
    // sort(arr, arr+5); // STL sort
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}

/*
Time Complexity: O(n log n) in all cases (best, average, worst) 
Space Complexity: O(n) due to temporary arrays used for merging
Explanation:
1. The mergeSort function recursively divides the array into halves until each sub-array contains a single
   element.
2. The merge function then merges these sub-arrays back together in sorted order.
3. This process continues until the entire array is sorted.
 
Expansion (Recursion Tree Method)
 
Level 0 (whole array): merging cost = O(n)
Level 1 (two halves): merging cost = 2 * O(n/2) = O(n)
Level 2 (four quarters): merging cost = 4 * O(n/4) = O(n)
 
Level log₂(n) (n single elements): merging cost = n * O(1) = O(n)
Each level costs O(n)
 
Number of Levels
Each time we divide array in half
Number of times until size = 1 is log₂(n)
 
sort(v.begin(), v.end()) usually uses Introsort (Quicksort + Heapsort + Insertion Sort), giving:
Average case: O(n log n)
Worst case: O(n log n)

*/