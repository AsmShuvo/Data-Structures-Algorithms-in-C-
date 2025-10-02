#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n){
    for(int i=0; i<n; i++){
        int key = a[i];
        int j = i-1;
        while (j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]= key;
    }
}

int main(){
    int a[]  = { 4,5,1,3,2};
    insertion_sort(a, 5);
    for(int i=0; i<5; i++) cout<<a[i]<<" ";
}

/*
Insertion sort:
Time complexity:  O(n^2)
Best case time complexity: O(n) 

Bubble sort:
Time complexity:  O(n^2)
Best case: O(n)

Merge sort: Best case/ Worst case: O(nLogn)

Selection:
Time comp: O(n^2)
Best case: O(n^2)
*/